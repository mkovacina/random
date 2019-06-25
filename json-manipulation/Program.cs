using System;
using System.IO;
using System.Linq;
using Newtonsoft.Json.Linq;

namespace json_manipulation
{
    class Program
    {
        static void Main(string[] args)
        {
            var data = File.ReadAllText("sample.json");
            var json = JObject.Parse(data);
            Console.WriteLine(json);

            var paths = "a:b:c:d:e:f".Split(':');

            var xp = "";
            int x = 0;
            for(x = 0; x < paths.Length - 1; x++)
            {
                var path = paths[x];

                var token = json.SelectToken(xp+"."+path);
                if (token == null)
                {
                    Console.WriteLine($"'{xp}' not found.");
                    break;
                }

                if (xp == string.Empty)
                {
                    xp = path;
                }
                else
                {
                    xp += "."+path;
                }
                Console.WriteLine($"'{xp}' found.");
            }

                var token2 = json.SelectToken(xp);
            for(; x < paths.Length-1;x++)
            {
               token2[paths[x]]=new JObject();
               xp += "." + paths[x];
               token2 = token2[paths[x]];
            }

            token2[paths.Last()]="encrypted string";
            Console.WriteLine(json.ToString());
        }
    }
}
