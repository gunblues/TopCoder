debug = False

def mylog(message):
    if(debug):
        print message

class RectangularGrid:
    def countRectangles(self, width, height):
        if type(width) is not int or type(height) is not int or width < 1 or width > 1000 or height < 1 or height > 1000:
            return 0

        total = 0

        for i in range(1, width+1):
            for j in range(1, height+1):
                if i != j:
                    sub_total = (width + 1 - i) * (height + 1 - j)
                    mylog("i:%d, j:%d - how many:%d" % (i, j, sub_total))
                    total = total + sub_total
            

        return total

print RectangularGrid().countRectangles(3, 3)
print RectangularGrid().countRectangles(5, 2)
print RectangularGrid().countRectangles(10, 10)
print RectangularGrid().countRectangles(1, 1)
print RectangularGrid().countRectangles(592, 964)

# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

