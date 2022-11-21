class Solution():
    def legalExp(self, str):
        s = []
        str_num = ""
        for i in str:
            if i == '#':
                s.append(int(str_num))
                str_num = ""
            elif i == '+': s.append(s.pop() + s.pop())
            elif i == '-': s.append(-(s.pop() - s.pop()))
            elif i == '*': s.append(s.pop() * s.pop())
            else: str_num += i
        return s[-1]


if __name__ == '__main__':
    test = Solution()
    print(test.legalExp("59455#696574#*45646#-"))