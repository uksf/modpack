#!/usr/bin/env python3
"""
Extract all AI Commander log lines from an Arma 3 RPT file.

Usage:
  python tools/extract_aic_rpt.py path\\to\\arma3.rpt
  python tools/extract_aic_rpt.py path\\to\\arma3.rpt -o aic.log
"""

from __future__ import annotations

import argparse
from pathlib import Path
import sys


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Extract [AIC] lines from an Arma 3 RPT file.")
    parser.add_argument("rpt_file", type=Path, help="Path to the .rpt file")
    parser.add_argument("-o", "--output", type=Path, help="Optional output file path")
    parser.add_argument(
        "--contains",
        type=str,
        default="",
        help="Optional case-insensitive substring filter after [AIC] match (e.g. CONTACT_REPORT)",
    )
    return parser.parse_args()


def extract_lines(rpt_path: Path, contains_filter: str) -> list[str]:
    if not rpt_path.exists():
        raise FileNotFoundError(f"RPT file not found: {rpt_path}")

    contains_filter = contains_filter.lower().strip()
    matches: list[str] = []

    with rpt_path.open("r", encoding="utf-8", errors="replace") as handle:
        for raw in handle:
            line = raw.rstrip("\n")
            if "[AIC]" not in line:
                continue
            if contains_filter and contains_filter not in line.lower():
                continue
            matches.append(line)

    return matches


def main() -> int:
    args = parse_args()

    try:
        matches = extract_lines(args.rpt_file, args.contains)
    except Exception as exc:  # noqa: BLE001
        print(f"ERROR: {exc}", file=sys.stderr)
        return 1

    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text("\n".join(matches) + ("\n" if matches else ""), encoding="utf-8")
        print(f"Wrote {len(matches)} AIC line(s) to {args.output}")
    else:
        for line in matches:
            print(line)
        print(f"\nMatched {len(matches)} AIC line(s).", file=sys.stderr)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
