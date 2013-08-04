class BigBurger:
    def maxWait(self, arrvial, service):
        length = len(arrvial)
        if type(arrvial) is not tuple or type(service) is not tuple or length < 1 or length > 50 or length != len(service):
            return False

        if length == 1:
           return 0
      
        maxVal, preWait, tmp = 0, 0, 0
        
        for i in range(0, length):

            if arrvial[i] < 1 or arrvial[i] > 720 or service[i] < 1 or service[i] > 15:
                    return False

            if i+1 < length:
                if arrvial[i+1] < arrvial[i]:
                    return False
               
                tmp = arrvial[i] + service[i] + preWait - arrvial[i+1] 
                if tmp > 0:
                    preWait = tmp

                if preWait > maxVal:
                    maxVal = preWait

            
        return maxVal 

bb = BigBurger()
print bb.maxWait((3, 3, 9), (2, 15, 14))
print bb.maxWait((182, ), (11, ))
print bb.maxWait((2, 10, 11), (3, 4, 3))
print bb.maxWait((2, 10, 12), (15, 1, 15))
 
# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

