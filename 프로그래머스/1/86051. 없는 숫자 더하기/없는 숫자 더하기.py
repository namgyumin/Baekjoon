def solution(numbers):
    answer = 0
    arr = [0 for _ in range(10)]
    set_number = set(numbers)
    for i in set_number:
        arr[i] = 1
    for i in range(10):
        if(arr[i] == 0):
            answer += i
    return answer