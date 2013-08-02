def gcd(a,b):
    if b==0: 
        return a
    else: 
        return gcd(b,a%b)

def mkinch(n):
    numer  = round((n-int(n))*1000/32.)
    thegcd = gcd(numer,32)

    integer = int(n)
    numerator = int(numer/thegcd)
    denominator = int(32/thegcd)

    if numer == 0.0:
        return integer

    numerator = numerator + integer * denominator

    return "%s/%s" % (numerator, denominator)

FRONT  = 0
BACK   = 1
UP     = 2
DOWN   = 3
LEFT   = 4
RIGHT  = 5

class Dragons:

    class Bowl:
        def __init__(self, original, steal):
            self.original = original
            self.steal = steal

    def initAllBowl(self, initialFood):
        self.foodStat = []
        idx = 0
        for food in initialFood:
            self.foodStat.append(self.Bowl(initialFood[idx], 0))
            idx = idx + 1

    def stealToOri(self):
        for side in range(FRONT, RIGHT+1):
            self.foodStat[side].original = self.foodStat[side].steal
            self.foodStat[side].steal = 0

    def stealFood(self, victim, sides):
        quarterFood = self.foodStat[victim].original / 4.0
        self.foodStat[victim].original = 0
        for side in sides:
            self.foodStat[side].steal += quarterFood

    def printBowl(self):
        rets = []
        for side in range(FRONT, RIGHT+1):
            rets.append(self.foodStat[side].original)
        print rets 

    def snaug(self, initialFood, rounds):

        self.initAllBowl(initialFood)

        for r in range(0, rounds):
            for side in range(FRONT, RIGHT+1):
                if self.foodStat[FRONT].original != 0:
                    self.stealFood(FRONT, [UP, DOWN, LEFT, RIGHT])
                elif self.foodStat[BACK].original != 0:
                    self.stealFood(BACK, [UP, DOWN, LEFT, RIGHT])
                elif self.foodStat[UP].original != 0:
                    self.stealFood(UP, [FRONT, BACK, LEFT, RIGHT])
                elif self.foodStat[DOWN].original != 0:
                    self.stealFood(DOWN, [FRONT, BACK, LEFT, RIGHT])
                elif self.foodStat[LEFT].original != 0:
                    self.stealFood(LEFT, [FRONT, BACK, UP, DOWN])
                elif self.foodStat[RIGHT].original != 0:
                    self.stealFood(RIGHT, [FRONT, BACK, UP, DOWN])

            self.stealToOri() 

        return mkinch(self.foodStat[UP].original)
            
print Dragons().snaug([0, 0, 4, 0, 0, 0], 2) 
print Dragons().snaug([0, 0, 4, 0, 0, 0], 3)
print Dragons().snaug([1000, 1000, 1000, 1000, 1000, 1000], 45)
print Dragons().snaug([1, 2, 3, 4, 5, 6], 45)
    
# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

