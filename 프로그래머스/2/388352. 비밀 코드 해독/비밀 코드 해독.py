from itertools import combinations

def solution(n, q, ans):
    answer = 0
    
    guess_sets = [set(a) for a in q]
    
    for comb in combinations(range(1, n+1), 5):
        val = True
        
        for i, guess_set in enumerate(guess_sets):
            temp = len(set(comb) & guess_set)
            if(temp != ans[i]):
                val = False;
                break;
                
        if(val == True):
            answer += 1
    
    return answer