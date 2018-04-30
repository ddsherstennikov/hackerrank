def ransom_note(magazine, ransom):
  ht = dict()
  
  for word in magazine:
    ht[word] = 1 if (word not in ht) else (ht[word] + 1) 
  
  for word in ransom:
    if (word not in ht or ht[word] <= 0): 
      return False
    else: ht[word] -= 1  
  
  return True

  
  
m, n = map(int, input().strip().split(' '))
magazine = input().strip().split(' ')
ransom = input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if(answer):
  print("Yes")
else:
  print("No")
    
