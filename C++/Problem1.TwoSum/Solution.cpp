class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			int currentElement = 0;
			int element = 0;
			for(auto startElement = nums.begin(); startElement != nums.end(); ++startElement) {
				element = currentElement;
				for(auto start = std::next(startElement); start != nums.end(); ++start) {
					++element;
					if (*startElement + *start == target) {
						std::vector<int> result{currentElement, element};
						return result;
					}
				}
				++currentElement;
			}
			vector<int> result {-1};
			return result;
		}
};
