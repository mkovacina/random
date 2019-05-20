using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Running;
using System.Linq;

namespace multiplicative_persistence_dotnet
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

	public class MultiplicativePersistenceStrategies
	{
		private string Input = "666";

		[Benchmark]
		public void Naive()
		{
			do
			{
				char[] digits = Input.ToCharArray();
				int acc = 1;
				foreach (char digit in digits)
				{
					acc = acc * (digit - '0');
				}

				if (acc < 10) break;

				Input = acc.ToString();

			} while (true);
		}

		[Benchmark]
		public void Better()
		{
			long x = long.Parse(Input);

			do
			{
				long acc = 1L;

				do
				{
					// yank the last digit
					long d = x % 10;
					// shrink x and drop the last digit
					x /= 10;

					acc *= d;
				} while (x > 0);

				if (acc < 10) break;

				x = acc;
			} while (true);
		}
	}
}
