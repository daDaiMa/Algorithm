
class SegTreeNode {
public:
  int start;
  int end;
  int min;
  SegTreeNode *left;
  SegTreeNode *right;
  SegTreeNode(int start, int end) {
    this->start = start;
    this->end = end;
    left = right = NULL;
  }
};

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    if (heights.size() == 0) return 0;
    SegTreeNode *root = buildSegmentTree(heights, 0, heights.size() - 1);
    return calculateMax(heights, root, 0, heights.size() - 1);
  }
  
  int calculateMax(vector<int>& heights, SegTreeNode* root, int start, int end) {
    if (start > end) {
      return -1;
    }
    if (start == end) {
      return heights[start];
    }
    int minIndex = query(root, heights, start, end);
    int leftMax = calculateMax(heights, root, start, minIndex - 1);
    int rightMax = calculateMax(heights, root, minIndex + 1, end);
    int minMax = heights[minIndex] * (end - start + 1);
    return max( max(leftMax, rightMax), minMax );
  }
  
  SegTreeNode *buildSegmentTree(vector<int>& heights, int start, int end) {
        if(start>end)return NULL;
        SegTreeNode* root = new SegTreeNode(start,end);
        if(start==end)root->min=start;
        else{
            int mid=start+(end-start)/2;
            root->left=buildSegmentTree(heights,start,mid);
            root->right=buildSegmentTree(heights,mid+1,end);
            root->min=heights[root->left->min]>heights[root->right->min]?root->right->min:root->left->min;
        }
        return root;
  }
  
  int query(SegTreeNode *root, vector<int>& heights, int start, int end) {
        if(end<root->start||start>root->end)return -1;
        if(start<=root->start&&end>=root->end)return root->min;
        int left_min_index=query(root->left,heights,start,end);
        int right_min_index=query(root->right,heights,start,end);
        if(left_min_index==-1)return right_min_index;
        if(right_min_index==-1)return left_min_index;
        return heights[left_min_index]>heights[right_min_index]?right_min_index:left_min_index;
  }
};
