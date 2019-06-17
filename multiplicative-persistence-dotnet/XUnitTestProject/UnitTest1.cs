using System;
using System.Diagnostics;
using Xunit;

namespace multiplicative_persistence_dotnet
{
	public class Tests
	{
		[Theory]
		[InlineData("6", 0)]
		[InlineData("12", 1)]
		[InlineData("999", 4)]
		[InlineData("7336", 5)]
		public void NaiveTest(string input, long length)
		{
			MultiplicativePersistenceStrategies x = new MultiplicativePersistenceStrategies
			{
				Input = input
			};
			x.Naive();

			Assert.Equal(length, x.Output);
		}

		[Theory]
		[InlineData("6", 0)]
		[InlineData("12", 1)]
		[InlineData("999", 4)]
		[InlineData("7336", 5)]
		public void BetterTest(string input, long length)
		{
			MultiplicativePersistenceStrategies x = new MultiplicativePersistenceStrategies
			{
				Input = input
			};
			x.Better();

			Assert.Equal(length, x.Output);
		}

		//[Theory]
		//[InlineData(1)]
		//[InlineData(2)]
		//public void Stopwatch(int method)
		//{
		//	Stopwatch sw = new Stopwatch();
		//	MultiplicativePersistenceStrategies x = new MultiplicativePersistenceStrategies();

		//	for (int i = 0; i < int.MaxValue/2; i++)
		//	{
		//		x.Input = i.ToString();
		//		switch (method)
		//		{
		//			case 1:
		//				x.Naive();
		//				break;
		//			case 2:
		//				x.Better();
		//				break;
		//			default:
		//				throw new ApplicationException();
		//		}
		//	}
		//}
	}
}