using System;
using System.Collections.Generic;
using System.Text;
using Xunit;

namespace multiplicative_persistence_dotnet
{
	public class Tests
	{
		[Theory]
		[InlineData("6",0)]
		[InlineData("12",1)]
		[InlineData("999",4)]
		[InlineData("7336", 5)]
		public void NaiveTest(string input, long length)
		{
			var x = new MultiplicativePersistenceStrategies();
			x.Input = input;
			x.Naive();

			Assert.Equal(length, x.Output);
		}

		[Theory]
		[InlineData("6",0)]
		[InlineData("12",1)]
		[InlineData("999",4)]
		[InlineData("7336", 5)]
		public void BetterTest(string input, long length)
		{
			var x = new MultiplicativePersistenceStrategies();
			x.Input = input;
			x.Better();

			Assert.Equal(length, x.Output);
		}
	}
}