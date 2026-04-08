#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void parse(int ac, char **av);
        void sort();
        void display() const;

    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;

        // --- vector implementation ---
        void                mergeInsertSort(std::vector<int> &v);
        void                insertPending(std::vector<int> &main, std::vector<int> &pending);
        std::vector<int>    buildJacobsthal(int n);

        // --- deque implementation ---
        void                mergeInsertSort(std::deque<int> &d);
        void                insertPending(std::deque<int> &main, std::deque<int> &pending);

        double _vecTime;
        double _deqTime;
};

#endif