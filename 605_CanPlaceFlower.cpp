class Solution
{
public
    boolean canPlaceFlowers(int[] flowerbed, int n)
    {
        int plantableSpots = 0;
        // Count number of empty adjacent places in plant bed.
        for (int i = 0; i < flowerbed.length; i++)
        {
            if (flowerbed[i] != 1)
            {
                boolean canPlantLeft = i == 0 || flowerbed[i - 1] != 1;
                boolean canPlantRight = i == flowerbed.length - 1 || flowerbed[i + 1] != 1;
                if (canPlantLeft && canPlantRight)
                {
                    flowerbed[i] = 1;
                    plantableSpots++;
                }
            }
        }
        return plantableSpots >= n;
    }
}