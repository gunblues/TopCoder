debug = False

def mylog(message):
    if(debug):
        print message

class PeopleCircle:
    
    def order(self, numMales, numFemales, K):
        if type(numMales) is not int or type(numFemales) is not int or type(K) is not int or numMales < 0 or numMales > 25 or numFemales < 0 or numFemales > 25 or K < 1 or K > 1000:
            return ''

        idx = 0
        total = numMales + numFemales
        ret = total * ['M']
        manCount = 0
        while numFemales > 0:
            pos = idx % total
            mylog("idx:%d, pos:%d, people:%s" % (idx, pos, ret[pos]))
            
            if ret[pos] == 'M':
                manCount = manCount + 1
                
                if manCount % K == 0:
                    mylog("before replace with female: %s" % ''.join(ret))
                    ret[pos] = 'F'
                    numFemales = numFemales - 1
                    mylog("after replace with female: %s" % ''.join(ret))

            idx = idx + 1

        return ''.join(ret)

print PeopleCircle().order(5, 3, 2)
print PeopleCircle().order(7, 3, 1)
print PeopleCircle().order(25, 25, 1000)
print PeopleCircle().order(5, 5, 3) 
print PeopleCircle().order(1, 0, 245)


# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

