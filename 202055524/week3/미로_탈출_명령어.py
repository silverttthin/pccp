import sys
sys.setrecursionlimit(30000000)

def solution(n, m, x, y, r, c, k):
    diff_x = x - r
    diff_y = y - c
    
    counter =  dict(map((lambda x: (x, 0)), "udlr"))
    
    if diff_x < 0:
        counter["d"] += abs(diff_x)
    else:
        counter["u"] += abs(diff_x)
    if diff_y < 0:
        counter["r"] += abs(diff_y)
    else:
        counter["l"] += abs(diff_y)
        
    manhattan_dist = abs(diff_x) + abs(diff_y)
    if k < manhattan_dist or (manhattan_dist - k) % 2 == 1:
        return "impossible"
    
    remain = k - manhattan_dist
    glob_path = ""
    def solve(x, y, remain, path):
        nonlocal glob_path
        
        if remain + sum(counter.values()) < abs(x - r) + abs(y - c):
            return
        
        if remain + sum(counter.values()) == 0:
            if x == r and y == c:
                if glob_path == "" or glob_path > path:
                    glob_path = path
                    assert False
            return
        
        if 1 <= x + 1 <= n and (remain + counter["d"] > 0):
            if counter["d"] > 0:
                counter["d"] -= 1
                solve(x + 1, y, remain, path + "d")
                counter["d"] += 1
            else:
                solve(x + 1, y, remain - 1, path + "d")
        if 1 <= y - 1 <= m and (remain + counter["l"] > 0):
            if counter["l"] > 0:
                counter["l"] -= 1
                solve(x, y - 1, remain, path + "l")
                counter["l"] += 1
            else:
                solve(x, y - 1, remain - 1, path + "l")
                
                
        if 1 <= y + 1 <= m and (remain + counter["r"] > 0):
            if counter["r"] > 0:
                counter["r"] -= 1
                solve(x, y + 1, remain, path + "r")
                counter["r"] += 1
            else:
                solve(x, y + 1, remain - 1, path + "r")
                
        if 1 <= x - 1 <= n and (remain + counter["u"] > 0):
            if counter["u"] > 0:
                counter["u"] -= 1
                solve(x - 1, y, remain, path + "u")
                counter["u"] += 1
            else:
                solve(x - 1, y, remain - 1, path + "u")
    try:
        solve(x, y, remain, "")
    except:
        return glob_path
