using BenchmarkDotNet.Attributes;
using System.Linq;


//	http://oeis.org/A031346

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

			MultiplicativePersistenceStrategies x = new MultiplicativePersistenceStrategies();

			for (int i = 0; i < int.MaxValue / 4; i++)
			{
				x.Input = i.ToString();
				x.Better();
			}
		}
	}
}

public class MultiplicativePersistenceStrategies
{
	public string Input = "666";
	public long Output = 0;

	[Benchmark]
	public void Naive()
	{
		do
		{
			if (Input.Trim().Length <= 1) break;

			Output++;

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

			if (x < 10) break;

			Output++;

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
