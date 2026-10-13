function parseSqf(text) {
  let i = 0;
  const space = () => { while (/\s/.test(text[i])) i++; };
  const value = () => {
    space();
    if (text[i] === '[') {
      i++;
      const items = [];
      space();
      if (text[i] === ']') { i++; return items; }
      for (;;) {
        items.push(value());
        space();
        if (text[i] === ',') { i++; continue; }
        if (text[i] === ']') { i++; return items; }
        throw new Error(`expected , or ] at ${i}: ${text.slice(i, i + 20)}`);
      }
    }
    if (text[i] === '"') {
      let out = '';
      i++;
      for (;;) {
        if (i >= text.length) throw new Error('unterminated string');
        if (text[i] === '"') {
          if (text[i + 1] === '"') { out += '"'; i += 2; continue; }
          i++;
          return out;
        }
        out += text[i++];
      }
    }
    const token = text.slice(i).match(/^[^,\]\s]+/);
    if (!token) throw new Error(`unexpected ${text.slice(i, i + 20)} at ${i}`);
    i += token[0].length;
    if (token[0] === 'true' || token[0] === 'false') return token[0] === 'true';
    const number = Number(token[0]);
    return Number.isNaN(number) ? token[0] : number;
  };
  const result = value();
  space();
  if (i !== text.length) throw new Error(`trailing text at ${i}: ${text.slice(i, i + 20)}`);
  return result;
}

function diff(a, b, tolerance = 1e-3, at = '') {
  if (typeof a === 'number' && typeof b === 'number') {
    return Math.abs(a - b) <= tolerance * Math.max(1, Math.abs(a)) ? [] : [`${at}: ${a} != ${b}`];
  }
  if (Array.isArray(a) && Array.isArray(b)) {
    if (a.length !== b.length) return [`${at}: length ${a.length} != ${b.length} (${JSON.stringify(a).slice(0, 120)} vs ${JSON.stringify(b).slice(0, 120)})`];
    return a.flatMap((item, n) => diff(item, b[n], tolerance, `${at}[${n}]`));
  }
  return a === b ? [] : [`${at}: ${JSON.stringify(a)} != ${JSON.stringify(b)}`];
}

module.exports = { parseSqf, diff };
