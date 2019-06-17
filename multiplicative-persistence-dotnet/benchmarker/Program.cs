using System;
using System.Linq;
using BenchmarkDotNet.Running;
using multiplicative_persistence_dotnet;

namespace benchmarker
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			string input = args.FirstOrDefault() ?? "666";

			// validate it is a number
			// ReSharper disable once ReturnValueOfPureMethodIsNotUsed
			long.Parse(input);
			BenchmarkDotNet.Reports.Summary summary = BenchmarkRunner.Run<MultiplicativePersistenceStrategies>();
		}
	}
}
