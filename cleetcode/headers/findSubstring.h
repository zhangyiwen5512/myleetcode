//
// Created by zhangyiwen on 2020/12/17.
//

#ifndef CLEETCODE_FINDSUBSTRING_H
#define CLEETCODE_FINDSUBSTRING_H

#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>

/*
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。
 * 找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 *
 *
 * 输入：
 * s = "barfoothefoobarman",
 * words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 *
 * 输入：
 * s = "wordgoodgoodgoodbestword",
 * words = ["word","good","best","word"]
 * 输出：[]
 *
 * 找出每个单词在s中的位置为起始头，
 * 滑动窗口w，判断窗口中的是否在words中，在则继续，否则返回
 *
 * tot words存数量，window存成功的words数量
 * j >= i + m * w，过头了，
 *
 *
 *
 *
 *
 *
 */



class findSubstring {
public:
    std::vector<int> Solution(std::string s, std::vector<std::string>& words) {
        std::vector<int> res;
        if(words.empty()) return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        std::unordered_map<std::string, int> tot;
        for(std::string& word: words)
            tot[word]++;
        // 枚举余数？
        for(int i = 0; i < w; i++)
        {
            int suc = 0;
            std::unordered_map<std::string, int> window;
            for(int j = i; j + w <= n; j += w)
            {
                if(j >= i + m * w)
                {
                    std::string cur = s.substr(j - m * w, w);
                    window[cur]--;
                    if(window[cur] < tot[cur])
                        suc--;
                }
                std::string cur = s.substr(j, w);
                window[cur] ++;
                if(window[cur] <= tot[cur])
                    suc++;
                if(suc == m)
                    res.push_back(j - (m - 1) * w);
            }
        }
        return res;


    }



};


#endif //CLEETCODE_FINDSUBSTRING_H
