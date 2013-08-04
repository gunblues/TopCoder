import sys

debug = False

def mylog(message):
    if(debug):
        print message

class MessageMess:
    
    def restore(self, dictionary, message):

        find = []
        tmpFind = {}
        lenMsg = len(message)
        isFind = False
        decodeMsg = ""

        for count in range(0, lenMsg):
            tmpFind[count] = []
            findIndexs = []
            start = 0
            for i in range(1, lenMsg + 1):
                try:
                    mylog("start:%d, i:%d, msg:%s" % (start, i, message[start:i]))
                    
                    idx = dictionary.index(message[start:i]) 
                    findIndexs.append(dictionary[idx]) 

                    sameVisitWay = False
                    if count > 0:
                        mylog("now visit way: %s" % (findIndexs))
                        for j in range(0, count):
                            mylog("visit way (%d): %s" % (j, tmpFind[j]))
                            if findIndexs == tmpFind[j]:
                                mylog("find the same visit way")
                                del findIndexs[-1]
                                mylog("modify visit way (%d): %s" % (count, findIndexs))
                                sameVisitWay = True
                                break

                    if sameVisitWay == True:
                        continue 
                    
                    tmpFind[count].append(dictionary[idx])
                    mylog("find:%d, %s" % (idx, dictionary[idx]))
                    start = start + len(dictionary[idx])
                except:
                    #mylog(sys.exc_info()[1])
                    pass

            mylog("final visit way:%s" % tmpFind[count])
   
            if "".join(tmpFind[count]) == message:
                decodeMsg = " ".join(tmpFind[count])
                find.append(tmpFind[count])
                isFind = True
           
            if count > 0 and isFind  == True and len(find) > 1:
                return "AMBIGUOUS!"
       
        if isFind == False:
            return "IMPOSSIBLE!"


        return decodeMsg

mm = MessageMess()
print mm.restore(("HI", "YOU", "SAY"), "HIYOUSAYHI")

print mm.restore(("ABC", "CD", "ABCB", "ABCBC"), "ABCABCBCCD")
print mm.restore(("ABC", "CD", "ABCB"), "ABCBCD")

print mm.restore(("ABC", "BCD", "CD", "ABCB"), "ABCBCD")
print mm.restore(("IMPOSS", "SIBLE", "S"), "IMPOSSIBLE")
print mm.restore(("IMPOSS", "SIBLE", "S", "IMPOSSIBLE"), "IMPOSSIBLE")

# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

