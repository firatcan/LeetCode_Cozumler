using System;

namespace leetcode28
{
    class Program
    {
        static int StrStr(string haystack, string needle)
        {
            if (string.IsNullOrEmpty(needle))
                return 0;
            return haystack.IndexOf(needle);
        } 
        static void Main(string[] args)
        {
            string haystack = "aaaa";
            string needle = "bba";
            int result = 0;
            result = StrStr(haystack, needle);

            Console.WriteLine("result: "+ result);
            Console.Read();
        }
    }
}
