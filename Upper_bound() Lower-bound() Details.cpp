upper_bound()=সমান বা ছোট এর Last পজিশন।
lower_bound()=ছোট এর Last পজিশন (সমান না)।
আর এই দুইটায় পজিশন প্রিন্ট দেয় (Index না)।

Ex(১):
int ar[] = {1,1,1,4,4,4}, n=6;
int upper = upper_bound (ar, ar+n, 2)-ar;
int lower = lower_bound (ar, ar+n, 2)-ar;
এখানে,
upper=3 (২ নাই, তাই Last ছোট পজিশন)।
lower=3 (lower_bound() তো আগেরটাই দেয়)।

Ex(২):
int ar[] = {1,1,1,2,4,4}, n=6;
int upper = upper_bound (ar, ar+n, 2)-ar;
int lower = lower_bound (ar, ar+n, 2)-ar;
এখানে,
upper=4 (২ আছে, তাই তার পজিশন)।
lower=3 (থাকলেও lower_bound() তো আগেরটাই দেয়)।
