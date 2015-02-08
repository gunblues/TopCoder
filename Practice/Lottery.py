import sys
import re
import operator

debug = True

def mylog(message):
    if(debug):
        print message

class Lottery:
    def sortByOdds(self, kinds):
        if type(kinds) is not list or len(kinds) == 0 or len(kinds) > 50:
            return []

        rules_odd = {}

        for kind in kinds:
            pos = kind.find(":")
            rpos = kind.rfind(":") 
            
            if pos == -1 or rpos == -1 or pos != rpos:
                return []

            rule = kind[0:pos]
            cols = kind[pos+1:].split(" ")

            if len(cols) != 5:
                return []
            
            try:
                choices = int(cols[1])
                blanks = int(cols[2])
                sort = cols[3]
                unique = cols[4]
                
                if re.match("^[A-Z ]{1,40}$", rule) == None:
                    mylog('rule error:' + rule)
                    return []
                if choices < 10 or choices > 100:
                    mylog('choices error:%d' % choices)
                    return []
                elif blanks < 1 or blanks > 8:
                    mylog('blanks error:%d' % blanks)
                    return []
                elif sort not in ['T', 'F']:
                    mylog('sort error:' + sort)
                    return []
                elif unique not in ['T', 'F']:
                    mylog('unique error:' + unique)
                    return []

                mylog("rule:{0}, choices:{1}, blanks:{2}, sored:{3}, unique:{4}".format(rule, choices, blanks, sort, unique))
               
                if sort == 'F' and unique == 'F':
                    odd = choices ** blanks
                elif sort == 'T' and unique == 'F':
                    odd = choices ** blanks - self.needSub(choices, blanks)
                elif sort == 'F' and unique == 'T':
                    odd = choices ** blanks - choices * (blanks - 1)
                elif sort == 'T' and unique == 'T':
                    odd = (1 + choices) * choices / 2 - choices * (blanks - 1)

                rules_odd[rule] = odd

            except:
                mylog(sys.exc_info()[1])
                return []

        sorted_rules = sorted(rules_odd.items(), key=lambda x: x[1])
        mylog(sorted_rules)

        ret = []
        for ele in sorted_rules:
            ret.append(ele[0])

        return ret

    def needSub(self, choices, blanks):
       
        total = 0
        for i in range(0, choices):
            total = total + (choices + i) * (choices - i - 1)

        total = total + choices * (choices - 1) / 2

        return total

print Lottery().sortByOdds(
    [
        "TEST: 93 8 T F",
        #"INDIGO: 93 8 T F",
        #"ORANGE: 29 8 F T",
        #"VIOLET: 76 6 F F",
        #"BLUE: 100 8 T T",
        #"RED: 99 8 T T",
        #"GREEN: 78 6 F T",
        #"YELLOW: 75 6 F F"
    ]
)

# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

