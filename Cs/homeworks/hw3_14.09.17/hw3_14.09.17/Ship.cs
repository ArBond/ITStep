using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw3_14._09._17
{
    public class Ship
    {

        private int[][,] ships = new int[10][,];
        private int shipCount = 0;

        public int ShipCount
        {
            get { return shipCount; }
        }

        public Ship()
        {
            int count = 0;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 3 - i; j < 4; j++)
                {
                    ships[count] = new int[4 - i, 2];
                    count++;
                }
            }
        }

        public void RandomSet(Field field)
        {
            var random = new Random();
            int count = 0;
            int xPos;
            int yPos;

            for (int i = 0; i < 4; i++)
            {
                for (int j = 3 - i; j < 4; j++)
                {
                    do
                    {
                        xPos = random.Next() % 10;
                        yPos = random.Next() % 10;
                        if (random.Next() % 2 == 0)
                        {
                            for (int k = 0; k < 4 - i; k++)
                            {
                                ships[count][k, 0] = xPos;
                                ships[count][k, 1] = yPos;
                                xPos++;
                            }
                        }
                        else
                        {
                            for (int k = 0; k < 4 - i; k++)
                            {
                                ships[count][k, 0] = xPos;
                                ships[count][k, 1] = yPos;
                                yPos++;
                            }
                        }
                    }
                    while (CheckSet(ships[count], field) == false);
                    for(int k = 0; k < 4 - i; k++)
                    {
                        field.cells[ships[count][k, 0], ships[count][k, 1]].IsShip = true;
                    }
                    count++;
                }
            }
            shipCount = count;
        }

        public void Set(Cursor cursor, Field field)
        {
            int[,] arr = { { cursor.GetPos()[1], cursor.GetPos()[0] } };
            if (CheckSet(arr, field))
            {
                field.cells[cursor.GetPos()[1], cursor.GetPos()[0]].IsShip = true;
                shipCount++;
            }
        }

        private bool CheckSet(int[,] ship, Field field)
        {
            for (int i = 0; i < ship.Length / 2; i++)
            {
                if (ship[i, 0] >= 10 || ship[i, 0] < 0 || ship[i, 1] >= 10 || ship[i, 1] < 0)
                    return false;

                int xPos = ship[i, 0] - 1;
                int yPos = ship[i, 1] - 1;

                if (yPos >= 0)
                {
                    if (xPos >= 0 && field.cells[xPos, yPos].IsShip == true)
                        return false;

                    xPos = ship[i, 0];
                    if (field.cells[xPos, yPos].IsShip == true)
                        return false;

                    xPos = ship[i, 0] + 1;
                    if (xPos < 10 && field.cells[xPos, yPos].IsShip == true)
                        return false;
                }

                xPos = ship[i, 0] - 1;
                yPos = ship[i, 1];
                if (xPos >= 0 && field.cells[xPos, yPos].IsShip == true)
                    return false;

                xPos = ship[i, 0];
                if (field.cells[xPos, yPos].IsShip == true)
                    return false;

                xPos = ship[i, 0] + 1;
                if (xPos < 10 && field.cells[xPos, yPos].IsShip == true)
                    return false;


                xPos = ship[i, 0] - 1;
                yPos = ship[i, 1] + 1;

                if (yPos < 10)
                {
                    if (xPos >= 0 && field.cells[xPos, yPos].IsShip == true)
                        return false;

                    xPos = ship[i, 0];
                    if (field.cells[xPos, yPos].IsShip == true)
                        return false;

                    xPos = ship[i, 0] + 1;
                    if (xPos < 10 && field.cells[xPos, yPos].IsShip == true)
                        return false;
                }
            }
            return true;
        }

        public bool Shot(Cursor cursor, Field field)
        {
            int xPos = cursor.GetPos()[0];
            int yPos = cursor.GetPos()[1];
            if (field.cells[yPos, xPos].IsShoted == true)
                return false;
            else
            {
                field.cells[yPos, xPos].IsShoted = true;
                if (field.cells[yPos, xPos].IsShip == true)
                {
                    DrowingCheck(new int[] { yPos, xPos }, field);
                    return false;
                }
                else
                    return true;
            }
        }

        public bool RandomShot(Field field)
        {
            var random = new Random();
            int xPos;
            int yPos;
            do
            {
                xPos = random.Next() % 10;
                yPos = random.Next() % 10;
            }
            while (field.cells[yPos, xPos].IsShoted == true);
            field.cells[yPos, xPos].IsShoted = true;
            if (field.cells[yPos, xPos].IsShip == true)
            {
                DrowingCheck(new int[] { yPos, xPos }, field);
                return false;
            }
            else
                return true;
        }

        private void DrowingCheck(int[] cell, Field field)
        {
            int count = 0;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 3 - i; j < 4; j++)
                {
                    for (int k = 0; k < 4 - i; k++)
                    {
                        if (ships[count][k, 0] == cell[0] && ships[count][k, 1] == cell[1])
                            goto label;
                    }
                    count++;
                }
            }
            label:
            {
                for(int i = 0; i < ships[count].Length / 2; i++)
                {
                    if (field.cells[ships[count][i, 0], ships[count][i, 1]].IsShoted == false)
                        return;
                }
                SetDrowed(ships[count], field);
            }
        }

        private void SetDrowed(int[,] ship, Field field)
        {
            shipCount--;
            for (int i = 0; i < ship.Length / 2; i++)
            {
                int xPos = ship[i, 0] - 1;
                int yPos = ship[i, 1] - 1;

                if (yPos >= 0)
                {
                    if (xPos >= 0)
                        field.cells[xPos, yPos].IsShoted = true;

                    xPos = ship[i, 0];
                    field.cells[xPos, yPos].IsShoted = true;

                    xPos = ship[i, 0] + 1;
                    if (xPos < 10)
                        field.cells[xPos, yPos].IsShoted = true;
                }

                xPos = ship[i, 0] - 1;
                yPos = ship[i, 1];
                if (xPos >= 0)
                    field.cells[xPos, yPos].IsShoted = true;

                xPos = ship[i, 0];
                field.cells[xPos, yPos].IsShoted = true;

                xPos = ship[i, 0] + 1;
                if (xPos < 10)
                    field.cells[xPos, yPos].IsShoted = true;


                xPos = ship[i, 0] - 1;
                yPos = ship[i, 1] + 1;

                if (yPos < 10)
                {
                    if (xPos >= 0)
                        field.cells[xPos, yPos].IsShoted = true;

                    xPos = ship[i, 0];
                    field.cells[xPos, yPos].IsShoted = true;

                    xPos = ship[i, 0] + 1;
                    if (xPos < 10)
                        field.cells[xPos, yPos].IsShoted = true;
                }
            }
        }

        public void Delete(Cursor cursor, Field field)
        {
            if (field.cells[cursor.GetPos()[1], cursor.GetPos()[0]].IsShip == true)
            {
                field.cells[cursor.GetPos()[1], cursor.GetPos()[0]].IsShip = false;
                shipCount--;
            }
        }
    }
}