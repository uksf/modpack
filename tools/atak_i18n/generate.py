import argparse
import json
import re
from pathlib import Path

PAIR = re.compile(r'^\s*\[\s*"((?:[^"]|"")*)"\s*,\s*"((?:[^"]|"")*)"')
BRAND = re.compile(r"(?<![\w/.-])(?:ATH[EÉ]NA|Ath[eé]na|athena|OVERWATCH|Overwatch|overwatch)(?![\w-]|\.\w)")
REPEAT = re.compile(r"\bTOC(\W{1,4})TOC\b")
OUTPUT = Path(__file__).resolve().parents[2] / "addons" / "atak" / "i18n_en_brand.txt"


def read_pairs(path):
    pairs = []
    for line in Path(path).read_text(encoding="utf-8").splitlines():
        match = PAIR.match(line)
        if match:
            pairs.append((match.group(1).replace('""', '"'), match.group(2).replace('""', '"')))
    return pairs


def rebrand(text):
    text = BRAND.sub("TOC", text)
    while REPEAT.search(text):
        text = REPEAT.sub("TOC", text)
    return text


def quote(text):
    return '"' + text.replace('"', '""') + '"'


def main():
    parser = argparse.ArgumentParser(description="Write UKSF English overrides that replace Athena and Overwatch branding in Modern ATAK text.")
    parser.add_argument("dictionaries", nargs="+", help="Extracted COMSPEC i18n/en.txt, then addons/atak/i18n_en.txt")
    parser.add_argument("--extra", help="JSON object of source text to English for branded strings missing from the dictionaries")
    args = parser.parse_args()
    merged = {}
    for path in args.dictionaries:
        merged.update(read_pairs(path))
    if args.extra:
        merged.update(json.loads(Path(args.extra).read_text(encoding="utf-8")))
    rows = []
    for source, english in merged.items():
        if BRAND.search(english) or BRAND.search(source):
            rows.append(f"[{quote(source)}, {quote(rebrand(english))}]")
    OUTPUT.write_text("[\n" + ",\n".join(rows) + "\n]\n", encoding="utf-8", newline="\r\n")
    print(f"{len(rows)} overrides -> {OUTPUT}")


main()
