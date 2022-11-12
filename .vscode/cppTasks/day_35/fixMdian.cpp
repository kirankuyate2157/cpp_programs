class MedianFinder
{
public:
    priority_queue<int> firstQ;
    priority_queue<int, std::vector<int>, std::greater<int>> secQ;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (firstQ.empty() || (firstQ.top() > num))
            firstQ.push(num); // if it belongs to the smaller half
        else
            secQ.push(num);

        // rebalance the two halfs to make sure the length difference is no larger than 1
        if (firstQ.size() > (secQ.size() + 1))
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if (firstQ.size() + 1 < secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        if (firstQ.size() == secQ.size())
            return firstQ.empty() ? 0 : ((firstQ.top() + secQ.top()) / 2.0);
        else
            return (firstQ.size() > secQ.size()) ? firstQ.top() : secQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */