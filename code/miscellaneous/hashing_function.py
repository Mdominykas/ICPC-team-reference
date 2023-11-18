import os
import hashlib
import re
import sys

def mkhash(dat):
  conc = ""
  for i in dat:
    conc += re.sub(r'\s*', '', i) + "\n"
    yield hashlib.md5(conc.encode('utf8')).hexdigest()[:2]

p = sys.argv[1]
MARGIN = int(sys.argv[2])


q = "suhashuotas.txt"

dat = [line for line in open(p, 'r').read().splitlines()]
out = open(q, 'w')

for dat_line, hash_val in zip(dat, mkhash(dat)):
  s = dat_line.lstrip(' ')
  add = len(dat_line) - len(s)
  if add > 0:
    s = ' ' + s
    add -= 1
  s = '-' * add + s
  if len(s) > MARGIN:
    print(s, file=out)
    if len(s) > MARGIN + 4:
      print(len(s), MARGIN)
      print(repr(s))
  else:
    if len(s) < MARGIN:
      s = s + ' '
    print(s.ljust(MARGIN, '-') + "//" + hash_val, file=out)

