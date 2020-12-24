int guess(int num);

int guessNumber(int n)
{
    int low = 1;
    int high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int result = guess(mid);
        if (result < 0)
        {
            low = mid + 1;
        }
        else if (result > 0)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return 0;
}

int main()
{
    return 0;
}