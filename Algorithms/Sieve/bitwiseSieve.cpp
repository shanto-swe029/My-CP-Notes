/*
	আমাদের ইম্প্লিমেন্টেশনে আমরা কোন নাম্বার মার্কড কিনা বোঝার জন্য বুলিয়ান অ্যারে রাখছি, তাই না? একটা bool অবজেক্টের সাইজ হচ্ছে 8 বিট। সাধারণত একটা বুলিয়ান ডাটা টাইপ মেশিনের addressable memory এর সবচে' ছোট ইউনিট এর সমান জায়গা নেয়। যেমন আমার মেশিনে সেটা হচ্ছে এক বাইট। আর এক বাইট মানে হচ্ছে 8 বিট। প্রতিটা বিট হচ্ছে একটা 0 অথবা 1। আমরা যদি কোনভাবে প্রতিটা বিটকে আলাদা আলাদা ব্যবহার করতে পারি সেটা মার্কড না আনমার্কড এটুকু ডাটা রাখার জন্য তাহলে আমাদের মেমরি ইউসেজ 8 গুণ কমে যাবে। আর তারপর যদি আমরা সব জোড় সংখ্যাকে উপেক্ষা করি, তাহলে সেটা সবমিলে আমাদের মেমরি ইউসেজ 16 গুণ কমিয়ে দেবে। একই সাথে বিট অপারেশনগুলো অনেক দ্রুত কাজ করে। সেটাও একটা প্লাস।

শুধু সমস্যা হচ্ছে সেটা করার জন্য তোমাকে বিট ম্যানিপুলেশন জানতে হবে (কিভাবে একটা নির্দিষ্ট বিটকে 0 অথবা 1 করবো বা ওটার ভ্যালু রিড করবো) আর কোডটা আরেকটু কম্প্লিকেটেড হবে। এখানে আমরা int ব্যবহার করছি যেটা হচ্ছে 32 বিট। কিন্তু আমরা বারবার 64 দিয়ে ভাগ করছি কারণ আমরা 2 মাল্টিপলদের হিসেবে ধরছি না।
*/

#define M 100000000
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(int n) {
  for (int i = 3; i * i < n; i += 2) {
    if (!on(i)) {
      for (int j = i * i; j <= n; j += i + i) {
        mark(j);
      }
    }
  }
}

bool isPrime(int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num))); 
}