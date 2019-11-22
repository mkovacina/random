// very quick-and-dirty reproduction of an example from a 
// Phillip Carter article entitled "Do It All with F# on
// .NET Core"

using System;
using BenchmarkDotNet;
using BenchmarkDotNet.Running;
using BenchmarkDotNet.Attributes;

namespace span_performance_reproduction
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
			var summary = BenchmarkRunner.Run<ParseBenchmarkTest>();
			Console.WriteLine(summary);
        }

		static class ParsingMethods
		{
			public static void ParseNumbers(string data, char delimiter)
			{
				var idx = data.IndexOf(delimiter);
				var first = Int32.Parse(data.Substring(0,idx));
				var second = Int32.Parse(data.Substring(idx+1));
			}

			public static void ParseNumbersFaster(string data, char delimiter)
			{
				var span = data.AsSpan();
				var idx = span.IndexOf(delimiter);
				var first = Int32.Parse(span.Slice(0,idx));
				var second = Int32.Parse(span.Slice(idx+1));
			}
		}

		[MemoryDiagnoser]
		public class ParseBenchmarkTest
		{
			private readonly string Data = "123,456";
			private const char Delimiter = ',';

			[Benchmark(Baseline=true)]
			public void GetNumbers()
			{
				ParsingMethods.ParseNumbers(Data,Delimiter);
			}

			[Benchmark]
			public void GetNumbersFaster()
			{
				ParsingMethods.ParseNumbersFaster(Data,Delimiter);
			}
		}
    }
}
