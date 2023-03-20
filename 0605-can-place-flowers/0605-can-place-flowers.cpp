class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (count(flowerbed.begin(), flowerbed.end(), 0) == flowerbed.size())
		{
			n -= (flowerbed.size() + 1) / 2;
			return n <= 0;
		}
		int i, cnt = 0, sz = flowerbed.size();
		for (i = 0; i < sz; i++)
		{
			if (flowerbed[i] == 0)
				cnt++;
			else
			{
				n -= cnt / 2;
				cnt = 0;
				break;
			}
		}
		for (; i < sz; i++)
		{
			if (flowerbed[i] == 0)
				cnt++;
			else
			{
				n -= (cnt - 1) / 2;
				cnt = 0;
			}
		}
		n -= cnt / 2;
		return n <= 0;
	}
};