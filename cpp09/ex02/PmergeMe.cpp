#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vec(other._vec), _deq(other._deq),
      _vecTime(other._vecTime), _deqTime(other._deqTime) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec     = other._vec;
        _deq     = other._deq;
        _vecTime = other._vecTime;
        _deqTime = other._deqTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}


void PmergeMe::parse(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string s(av[i]);

        for (size_t j = 0; j < s.size(); j++)
        {
            if (s[j] < '0' || s[j] > '9')
                throw std::runtime_error("Error");
        }
        if (s.empty())
            throw std::runtime_error("Error");

        std::istringstream iss(s);
        long n;
        iss >> n;

        if (n <= 0 || n > 2147483647)
            throw std::runtime_error("Error");

        _vec.push_back(static_cast<int>(n));
        _deq.push_back(static_cast<int>(n));
    }

    if (_vec.empty())
        throw std::runtime_error("Error: no input");
}

static std::vector<int> buildJacobsthal(int n)
{
    std::vector<int> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (true)
    {
        int next = jac[jac.size() - 1] + 2 * jac[jac.size() - 2];
        if (next >= n)
            break;
        jac.push_back(next);
    }
    return jac;
}

static void binaryInsertVec(std::vector<int> &chain, int value, int bound)
{
    int lo = 0, hi = bound;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (chain[mid] < value) lo = mid + 1;
        else                    hi = mid;
    }
    chain.insert(chain.begin() + lo, value);
}

static void binaryInsertDeq(std::deque<int> &chain, int value, int bound)
{
    int lo = 0, hi = bound;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (chain[mid] < value) lo = mid + 1;
        else                    hi = mid;
    }
    chain.insert(chain.begin() + lo, value);
}

static void fordJohnsonVec(std::vector<int> &v)
{
    int n = static_cast<int>(v.size());
    if (n <= 1)
        return ;

    bool hasStraggler = (n % 2 != 0);
    int  straggler    = hasStraggler ? v[n - 1] : 0;
    int  pairCount    = n / 2;

    std::vector<std::pair<int,int> > pairs;
    for (int i = 0; i < pairCount; i++)
    {
        int a = v[2 * i], b = v[2 * i + 1];
        if (a >= b) pairs.push_back(std::make_pair(a, b));
        else        pairs.push_back(std::make_pair(b, a));
    }

    std::vector<int> winners;
    for (int i = 0; i < pairCount; i++)
        winners.push_back(pairs[i].first);

    fordJohnsonVec(winners);

    std::vector<std::pair<int,int> > sortedPairs = pairs;
    for (int i = 0; i < pairCount - 1; i++)
        for (int j = i + 1; j < pairCount; j++)
            if (sortedPairs[i].first > sortedPairs[j].first)
                std::swap(sortedPairs[i], sortedPairs[j]);

    std::vector<int> mainChain;
    mainChain.push_back(sortedPairs[0].second);
    for (int i = 0; i < pairCount; i++)
        mainChain.push_back(winners[i]);

    std::vector<int> pending;
    for (int i = 1; i < pairCount; i++)
        pending.push_back(sortedPairs[i].second);
    if (hasStraggler)
        pending.push_back(straggler);

    int pSize = static_cast<int>(pending.size());
    if (pSize > 0)
    {
        std::vector<int> order;
        std::vector<bool> inserted(pSize, false);
        std::vector<int> jac = buildJacobsthal(pSize + 1);

        for (size_t k = 1; k < jac.size(); k++)
        {
            int hi = jac[k] - 1;
            int lo = jac[k - 1];
            if (hi >= pSize) hi = pSize - 1;
            for (int idx = hi; idx >= lo; idx--)
                if (!inserted[idx]) { order.push_back(idx); inserted[idx] = true; }
        }
        for (int idx = pSize - 1; idx >= 0; idx--)
            if (!inserted[idx]) order.push_back(idx);

        for (size_t i = 0; i < order.size(); i++)
            binaryInsertVec(mainChain, pending[order[i]], static_cast<int>(mainChain.size()));
    }

    v = mainChain;
}

static void fordJohnsonDeq(std::deque<int> &d)
{
    int n = static_cast<int>(d.size());
    if (n <= 1)
        return;

    bool hasStraggler = (n % 2 != 0);
    int  straggler    = hasStraggler ? d[n - 1] : 0;
    int  pairCount    = n / 2;

    std::vector<std::pair<int,int> > pairs;
    for (int i = 0; i < pairCount; i++)
    {
        int a = d[2 * i], b = d[2 * i + 1];
        if (a >= b) pairs.push_back(std::make_pair(a, b));
        else        pairs.push_back(std::make_pair(b, a));
    }

    std::deque<int> winners;
    for (int i = 0; i < pairCount; i++)
        winners.push_back(pairs[i].first);

    fordJohnsonDeq(winners);

    std::vector<std::pair<int,int> > sortedPairs = pairs;
    for (int i = 0; i < pairCount - 1; i++)
        for (int j = i + 1; j < pairCount; j++)
            if (sortedPairs[i].first > sortedPairs[j].first)
                std::swap(sortedPairs[i], sortedPairs[j]);

    std::deque<int> mainChain;
    mainChain.push_back(sortedPairs[0].second);
    for (int i = 0; i < pairCount; i++)
        mainChain.push_back(winners[i]);

    std::deque<int> pending;
    for (int i = 1; i < pairCount; i++)
        pending.push_back(sortedPairs[i].second);
    if (hasStraggler)
        pending.push_back(straggler);

    int pSize = static_cast<int>(pending.size());
    if (pSize > 0)
    {
        std::vector<int> order;
        std::vector<bool> inserted(pSize, false);
        std::vector<int> jac = buildJacobsthal(pSize + 1);

        for (size_t k = 1; k < jac.size(); k++)
        {
            int hi = jac[k] - 1;
            int lo = jac[k - 1];
            if (hi >= pSize) hi = pSize - 1;
            for (int idx = hi; idx >= lo; idx--)
                if (!inserted[idx]) { order.push_back(idx); inserted[idx] = true; }
        }
        for (int idx = pSize - 1; idx >= 0; idx--)
            if (!inserted[idx]) order.push_back(idx);

        for (size_t i = 0; i < order.size(); i++)
            binaryInsertDeq(mainChain, pending[order[i]], static_cast<int>(mainChain.size()));
    }

    d = mainChain;
}

void PmergeMe::sort()
{
    std::vector<int> original = _vec;

    std::clock_t start = std::clock();
    fordJohnsonVec(_vec);
    std::clock_t end = std::clock();
    _vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

    start = std::clock();
    fordJohnsonDeq(_deq);
    end = std::clock();
    _deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "Before:";
    for (size_t i = 0; i < original.size(); i++)
        std::cout << " " << original[i];
    std::cout << std::endl;

    std::cout << "After:";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << _vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << _deqTime << " us" << std::endl;
}

void PmergeMe::display() const {}