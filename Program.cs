using System;

namespace Giraffe
{
    class Program
    {

        static Random getRandom = new Random();

        /* Source: https://www.geeksforgeeks.org/estimating-value-pi-using-monte-carlo/
         This approach estimates the value of pi with a Monte Carlo method
         Approximates the area of the circle and from it the value of pi is relfected from the formula
         The randomly generated points in this case follow an uniform distribution
         Any position has the equal probability of being chosen
         It is supossed that all the parts of the square are equally filled, theorically there wont a big agrupation 
         */
        static double MonteCarloUniform(int resources)
        {
            double circlePoints = 0;  // Amount of points that fall inside the circle
            double squarePoints = 0;  // Amount of points that fall inside the square (total of all points)

            double X, Y;  // Variables for 2d coordenates

            while (squarePoints < resources)
            {
                // Sets a random x, y position
                // Its uniform, therefore any number in the interval has the same chance of being returned
                X = getRandom.NextDouble();
                Y = getRandom.NextDouble();


                // Determines if the point is inside the circle
                if (X*X + Y*Y <= 1)
                {
                    circlePoints++;
                }

                squarePoints++;
            }


            // Reflects the value from the equation of the formula
            return 4*(circlePoints/squarePoints);
        }



        /*This method returns a random number from a normal distribution
          This normal has distribution has mean 0 (0 = center)
          The standard desviation is 0.28, it adapts well to our range [-1, 1]
         */
        static double generateNormalValue()
        {
            double u1 = 1.0 - getRandom.NextDouble();
            double randStdNormal = Math.Sqrt(-2.0 * Math.Log(u1));  // At this point we have an standarized normal distribution (mean = 0, std des = 1)

            double randNormal = 0.28 * randStdNormal;  // mean + stdDev * randStdNormal -> 0 + 0.28*randStdNormal

            return randNormal;
        }


        /* This approach estimates the value of pi with a Monte Carlo method
         Approximates the area of the circle and from it the value of pi is relfected from the formula
         The randomly generated points in this case follow an normal distribution
         More points will be generated around the mean and few will appear far from it
         How far a point can appear is determined by the standard desviation 
         */
        static double MonteCarloNormal(int resources)
        {
            double circlePoints = 0;  // Amount of points that fall inside the circle
            double squarePoints = 0; // Amount of points that fall inside the square (total of all points)

            double X, Y;  // Variables for 2d coordenates

            while (squarePoints < resources)
            {
                // Sets a random x, y position
                // Its normal, therefore numbers closer to the mean have higger probability of being selected ad the ones far from the mean have low probability
                X = generateNormalValue();
                Y = generateNormalValue();

                if (X > 1 || Y > 1)
                {
                    continue;
                }

                // Determines if the point is inside the circle
                if (X*X + Y*Y <= 1)
                {
                    circlePoints++;
                }

                squarePoints++;
            }

            // Reflects the value from the equation of the formula
            return 4 * (circlePoints / squarePoints);

        }


        // testing
        static void Main(string[] args)
        {
            const int resources = 100000;  // The amount of resources that will be destined for the approximation, remmeber both are MonteCarlo

            // Needed to get an average later
            double normalSum = 0;
            double uniformSum = 0;

            // Hold a single approximation
            double uniform;
            double normal;

            const short iterations = 100;
            for (int i = 0; i < iterations; i++)
            {
                // Gets and prints a single uniform approximation, also add it for the average
                uniform = MonteCarloUniform(resources);
                Console.WriteLine(uniform);
                uniformSum += uniform;

                // Gets and prints a single normal approximation, also add it for the average
                normal = MonteCarloNormal(resources);
                Console.WriteLine(normal);
                normalSum += normal;
            }

            Console.WriteLine("Uniform average: " + (uniformSum/iterations));  // Prints the uniform average
            Console.WriteLine("Normal average: " + (normalSum /iterations));  // Prints the normal average
        }


    }

}
 