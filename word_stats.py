#!/usr/bin/env python

import sys

def statify(s):
  lst = s.split()
  items = [] 
  res_dict = {} # { len:[word,word,word]}
  for word in lst:
    if len(word) in res_dict.keys():
	  res_dict[len(word)].append(word)
    else:
      res_dict[len(word)] = [word]

  # items = [ (lenght of word,no.of same length reps,[word,word,word]) ]
  for item in res_dict.items():
    items.append((item[0],len(item[1]),item[1]))
  
  # First sort by no.of reps then length of word
  items = sorted(items,key=lambda element:(element[1],0-element[0]))

  # flatten using list comprehension and build the result string
  result = '\n'.join([ word for tup in items for word in tup[2] ])
  
  print result
  
def main():
  fname = sys.argv[1]
  #print 'Trying to open ', fname
  f = open(fname,"r");
  content = f.read()
  statify(content)
  
if __name__ == '__main__':
  main()