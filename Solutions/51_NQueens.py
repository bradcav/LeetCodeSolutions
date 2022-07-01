class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        colUsed = set()     #store which columns have been used
        posDiagUsed = set() #which positive diagonals have been used? index using r+c
        negDiagUsed = set() #indexed using r-c
        
        res = []
        
        temp = [["."] * n for i in range(n)]  #start with empty board
        
        #place a queen row by row in first possible space
        def backtrack(row):
            
            #base case: row == n, found a valid solution. Add copy of temp to result
            if row == n:
                temp_copy = ["".join(row) for row in temp]
                res.append(temp_copy)
                return
        
            #try all columns in the current row
            for col in range(n):
                #can queen be placed here?
                if col in colUsed or (row+col) in posDiagUsed or (row-col) in negDiagUsed:
                    continue
                
                #can be used, so update the sets and temp board
                colUsed.add(col)
                posDiagUsed.add(row+col)
                negDiagUsed.add(row-col)    
                temp[row][col] = "Q"
                
                #move to next row
                backtrack(row + 1)
                
                #backtrack - undo 
                colUsed.remove(col)
                posDiagUsed.remove(row+col)
                negDiagUsed.remove(row-col)
                temp[row][col] = "."
                                
        
        backtrack(0)        
        
        return res
        