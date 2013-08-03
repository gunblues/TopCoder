import itertools

def unique(iterable):
    seen = set()
    for x in iterable:
        if x in seen:
            continue
        seen.add(x)
        yield x

class MNS:
    def combos(self, numbers):
        for ele in numbers:
            if(ele < 0 or ele > 9):
                return 0;

        numbers.sort()
        count = 0 
        for ele in unique(itertools.permutations(numbers)):
            if(
                ele[0] + ele[1] + ele[2] == 
                ele[3] + ele[4] + ele[5] == 
                ele[6] + ele[7] + ele[8] == 
                ele[0] + ele[3] + ele[6] == 
                ele[1] + ele[4] + ele[7] == 
                ele[2] + ele[5] + ele[8] 
            ):

                count = count + 1
        return count

print MNS().combos([1, 2, 3, 3, 2, 1, 2, 2, 2]);
print MNS().combos([4, 4, 4, 4, 4, 4, 4, 4, 4]);
print MNS().combos([1, 5, 1, 2, 5, 6, 2, 3, 2]);
print MNS().combos([1, 2, 6, 6, 6, 4, 2, 6, 4]);

# vim: expandtab softtabstop=4 tabstop=4 shiftwidth=4 ts=4 sw=4

