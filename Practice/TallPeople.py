class TallPeople:
    def getPeople(self, people):
        minsRow = [] 
        maxsCol = []
        
        for x, row in enumerate(people):
            col = row.split()
            
            minRow = col[0]
            
            for y, val in enumerate(col):
                if val < minRow:
                    minRow = val

                if x == 0:
                    maxsCol.append(val)
                
                if val > maxsCol[y]:
                    maxsCol[y] = val

            minsRow.append(minRow)

        return (max(minsRow), min(maxsCol))


tp = TallPeople()
print tp.getPeople(("9 2 3", "4 8 7"))


# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

