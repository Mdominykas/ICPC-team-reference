import os
import hashlib
import re

MARGIN = 100 - 40 - 8 + 7

def mkhash(dat):
    conc = ""
    for i in dat:
        conc += re.sub(r'\s*', '', i) + "\n"
        yield hashlib.md5(conc.encode('utf8')).hexdigest()[:2]

for path, dirs, files in os.walk('./code'):
    for f in files:
        if (f.endswith(".cpp") or f.endswith('.java') or f.endswith('.sh')) and not f.endswith(".test.cpp"):
            p = os.path.join(path, f)
            q = os.path.join("_code", '/'.join(path.split('/')[2:]), f)

            try:
                os.makedirs(os.path.dirname(q))
            except FileExistsError:
                pass

            dat = [line for line in open(p, 'r').read().splitlines() if not line.startswith('// vim: ') and not line.startswith('# vim: ')]
            out = open(q, 'w')

            warning = False
            error = False
            last = False
            for dat_line, hash_val in zip(dat, mkhash(dat)):
                last = False
                s = dat_line.lstrip(' ')
                add = len(dat_line) - len(s)
                if add > 0:
                    s = ' ' + s
                    add -= 1
                s = '-' * add + s
                if len(s) > MARGIN:
                    print(s, file=out)
                    warning = True
                    last = True
                    if len(s) > MARGIN + 4:
                        error = True
                        print(len(s), MARGIN)
                        print(repr(s))
                else:
                    if len(s) < MARGIN:
                        s = s + ' '
                    print(s.ljust(MARGIN, '-') + "//" + hash_val, file=out)

            if last:
                error = True
            if error:
                print('ERROR: Code too wide: %s' % p)
            elif warning:
                print('WARNING: Code (almost) too wide: %s' % p)