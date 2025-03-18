# 10799 / 쇠막대기 / boj
# 52ms
# 20분 소요

# innermost parens => laser
# others => iron stick

def parse(string):
    acc = 0
    stack = []

    i = 0
    while i < len(string):
        if string[i] == '(' and string[i + 1] == ')':
            level = len(stack)
            acc += level
            i += 2
        elif string[i] == '(':
            stack.append(string[i])
            i += 1
        else:
            stack.pop()
            acc += 1
            i += 1
    return acc

string = input()
print(parse(string))
