// remember, this is a PDQ
// much like an AMRAP
// don't sacrifice form
// but speed is the goal
//

using System;

namespace innovation_model
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

			var model = new InnovationModel(
					100000,
					10,
					3,
					2,
					10000,
					Guid.NewGuid().GetHashCode());
					//31415926);

			model.go();
        }
    }

	class InnovationModel
	{
		// not creating a parameters struct as this is a PDQ

		public InnovationModel(
				long urnSize,
				long initialNumberOfElements, 
				long numberOfSelectedElementCopies, 
				long numberOfNewElements,
				long numberOfIterations,
				int randomSeed)
		{
			// todo: validate parameter ranges
			// todo: validate urn size versus initial number of elements
			UrnSize = urnSize;
			InitialNumberOfElements = initialNumberOfElements;
			NumberOfSelectedElementCopies = numberOfSelectedElementCopies;
			// the '+1' comes from the paper...
			// haven't quite figured out why
			NumberOfNewElements = numberOfNewElements + 1;
			NumberOfIterations = numberOfIterations;
			RandomSeed = randomSeed;

			Urn = new long[UrnSize];
			// pdq: fixed max number of new ideas
			History = new long[9999];
		}

		public long UrnSize {get;}
		public long InitialNumberOfElements {get;}
		public long NumberOfSelectedElementCopies {get;}
		public long NumberOfNewElements {get;}
		public long NumberOfIterations {get;}
		public int RandomSeed {get;}

		// pdq: avoid the collections library for now, go old school
		public long[] Urn;
		public int UrnCount;
		public long[] History;

		// using an increasing integer sequence for "new ideas"
		private long IdeaGenerator = 0;

		public void go()
		{
			Initialize();	
	
			var rng = new Random(RandomSeed);

			for(long iteration = 0; iteration < NumberOfIterations; iteration++)
			{
				Console.WriteLine($"# Iteration: {iteration}");
				var selectionIndex = rng.Next(0, UrnCount);	
				Console.WriteLine($"# Selection Index: {selectionIndex}");
				var selection = Urn[selectionIndex];
				Console.Out.WriteLine($"# Selected: {selection}");
				History[selection]++;
				
				// add new copies of the selected element
				for(int x = 0; x < NumberOfSelectedElementCopies; x++)
				{
					Urn[UrnCount] = selection;
					UrnCount++;
				}

				if (History[selection] == 1)
				{
					Console.WriteLine("# Innovating...");
					for(int x = 0; x < NumberOfNewElements; x++)
					{
						Urn[UrnCount] = IdeaGenerator;
						UrnCount++;
						IdeaGenerator++;
					}
				}
				
				Console.WriteLine($"# UrnCount: {UrnCount}");
				Console.WriteLine($"# IdeaGenerator: {IdeaGenerator}");
				Console.WriteLine($"{iteration},{selectionIndex},{selection},{UrnCount},{IdeaGenerator}");
				

				Console.WriteLine();
			}
		}

		private void Initialize()
		{
			for(int x = 0; x < InitialNumberOfElements; x++)
			{
				Urn[x] = IdeaGenerator;
				IdeaGenerator++;
				UrnCount++;
			}
		}
	}
}
