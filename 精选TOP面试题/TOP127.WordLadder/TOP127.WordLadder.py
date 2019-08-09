
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # 双向广度得有俩set
        s1 = set()
        s2 = set()
        s1.add(beginWord)
        s2.add(endWord)
        #  用一个set保存单词
        wordset = set(wordList)
        if endWord not in wordset:
            return 0
        step = 0

        charlist = [chr(i+97) for i in range(26)]
        while(len(s1) and len(s2)):
            # 从小的set开始扩展
            if len(s1) > len(s2):
                s1, s2 = s2, s1
            # 用一个set接住扩展出来的结果
            next = set()
            step += 1
            # 遍历s1每一个单词 尝试修改其中一个字母
            for word in s1:
                for index in range(len(word)):
                    # 尝试每一种修改
                    for char in charlist:
                        # 生成一个新的单词
                        nw = word[:index]+char+word[index+1:]
                        # 看看单词在不在s2中
                        if nw in s2:
                            return step+1
                        if nw not in wordset:
                            continue
                        wordset.remove(nw)
                        next.add(nw)
            s1 = next

        return 0
