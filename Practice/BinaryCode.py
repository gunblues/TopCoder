debug = False

def mylog(message):
    if(debug):
        print message

class BinaryCode:
    def decode(self, encrypted):

        if type(encrypted) is not str or encrypted == "":
            return ["NONE", "NONE"]

        rets = []
        for group in range(0,2):
            if group == 0:
                return_str = "0"
            else:
                return_str = "1"

            idx = 0
            for char in encrypted:

                mylog("encrypted:"+encrypted[idx])
                mylog("return_str:"+return_str[idx])

                total_need_sub = 0

                if idx == 0:
                    start = 0
                else:
                    start = idx - 1

                for i in range(start, idx+1):
                    total_need_sub += int(return_str[i])

                original = str(int(encrypted[idx]) - int(total_need_sub)) 

                mylog("original:"+original)
                if original != "0" and original != "1":
                    return_str = "NONE"
                    break

                return_str += original
                mylog("return_str:"+return_str)

                idx = idx + 1

            if(return_str != "NONE"):
                return_str = return_str[:-1]

            rets.append(return_str)

        return rets


print BinaryCode().decode("123210122")
print BinaryCode().decode("11")
print BinaryCode().decode("22111")
print BinaryCode().decode("123210120")
print BinaryCode().decode("3")
print BinaryCode().decode("12221112222221112221111111112221111")

# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

