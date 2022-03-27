#include <bits/stdc++.h>
using namespace std;
class Box
{
public:
    int l;
    int h;
    int w;
};
int dp[1001];
 
// recursion or DP approch
int findMaxHeight(vector<Box>& boxes, int bottom_box_index, int index)
{
 
    // base case
    if (index < 0)
        return 0;
 
    if (dp[index] != -1)
        return dp[index];
 
    int maximumHeight = 0;
 
    // recurse
    for (int i = index; i >= 0; i--) {
 
        // if there is no bottom box
        if (bottom_box_index == -1
 
            // or if length & width of new box is < that of
            // bottom box
            || (boxes[i].l< boxes[bottom_box_index].l&& boxes[i].w< boxes[bottom_box_index].w))
 
            maximumHeight= max(maximumHeight,findMaxHeight(boxes, i, i - 1) + boxes[i].h);
    }
 
    return dp[index] = maximumHeight;
}



// itrative aproch
int maxheight(vector<Box> box)
{
    memset(dp, -1, sizeof(dp));
    int n = box.size();
    int Max[n];
    int index[n];
    // memset(Max, -1, sizeof(Max));
    for (int i = 0; i < n; i++)
    {
        Max[i] = box[i].h;
        index[i] = i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (box[j].w > box[i].w && box[j].l > box[i].l && Max[j] + box[i].h > Max[i])
            {

                Max[i] = Max[j] + box[i].h;
                index[i] = j;
            }
        }
    }int ans=0;
    for (int x : Max){
        if(x>ans)ans=x;
        // cout << x << " ";
        }
    return ans;
}



int boxArrag(int length[], int width[], int height[], int n)
{
    vector<Box> boxes;
    for (int i = 0; i < n; i++)
    {
        Box box;
        box.h = height[i];
        box.l = max(width[i], length[i]);
        box.w = min(width[i], length[i]);
        boxes.push_back(box);

        box.h = length[i];
        box.l = max(width[i], height[i]);
        box.w = min(width[i], height[i]);
        boxes.push_back(box);

        box.h = width[i];
        box.l = max(height[i], length[i]);
        box.w = min(height[i], length[i]);
        boxes.push_back(box);
    }
    sort(boxes.begin(), boxes.end(), [](Box b1, Box b2)
         { return (b1.l * b1.w) > (b2.l * b2.w); });

    // for (int i = 0; i < boxes.size(); i++)
    // {
    //     cout << boxes[i].l * boxes[i].w << "  ->" << boxes[i].l << "  " << boxes[i].w << "  " << boxes[i].h << "\n";
    // }
    return findMaxHeight(boxes,-1,n-1);
}
int main()
{
    int length[] = {4, 1, 4, 10};
    int width[] = {6, 2, 5, 12};
    int height[] = {7, 3, 6, 32};

    int n = sizeof(length) / sizeof(length[0]);
    cout << boxArrag(length, width, height, n);
    return 0;
}