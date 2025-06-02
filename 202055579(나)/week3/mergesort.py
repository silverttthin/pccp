n=int(input())
lst = list(map(int, input().split()))

# merge two sorted lst left and right
def merge(left, right):
    result = []
    i=0
    j=0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    
    # Since the remaining parts are already sorted just extend the remaining parts!!
    result.extend(left[i:]) 
    result.extend(right[j:])
    return result


def merge_sort(lst):
    if len(lst) <= 1: return lst # base condition

    # DIVIDE
    mid = len(lst) // 2
    left = merge_sort(lst[:mid])
    right = merge_sort(lst[mid:])

    return merge(left, right)

print(*merge_sort(lst))
