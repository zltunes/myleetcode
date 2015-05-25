class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum_nlgn(self, nums, target):
        s_nums = [[y, x] for x, y in enumerate(nums, 1)]
        s_nums.sort()
        i = 0
        j = len(s_nums) - 1
        while i < j:
            t = s_nums[i][0] + s_nums[j][0]
            if t == target:
                it1 = s_nums[i][1]
                it2 = s_nums[j][1]
                return [min(it1, it2), max(it1, it2)]
            elif t < target:
                i += 1
            else:
                j -= 1
        return []

    def twoSum_n(self, nums, target):
        scanned = {}
        for j, item in enumerate(nums, 1):
            i = scanned.get(target - item, -1)
            if i > 0:
                return [i, j]
            scanned[item] = j

def main():
    nums = [2,11,7,15]
    target = 9
    sol = Solution()
    print sol.twoSum_n(nums, target)

if __name__ == "__main__":
    main()
