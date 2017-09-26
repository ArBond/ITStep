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
        private int[] shipLengths = {0, 4, 3, 2, 1 };

        private bool shipSetting = false;
        private int[] shipBeginPos = new int[2];

        private bool isDamagedShip = false;
        private int damageCountOfShip = 0;
        private int xPosOfShot;
        private int yPosOfShot;
        private int xPosOfFirstHit;
        private int yPosOfFirstHit;
        private int xPosOfSecondHit;
        private int yPosOfSecondHit;

        public int ShipCount
        {
            get { return shipCount; }
        }

        public void RandomSet(Field field)
        {
            var random = new Random();
            int xPos;
            int yPos;

            for (int i = 0; i < 4; i++)
            {
                for (int j = 3 - i; j < 4; j++)
                {
                    ships[shipCount] = new int[4 - i, 2];
                    do
                    {
                        xPos = random.Next() % 10;
                        yPos = random.Next() % 10;
                        if (random.Next() % 2 == 0)
                        {
                            for (int k = 0; k < 4 - i; k++)
                            {
                                ships[shipCount][k, 0] = xPos;
                                ships[shipCount][k, 1] = yPos;
                                xPos++;
                            }
                        }
                        else
                        {
                            for (int k = 0; k < 4 - i; k++)
                            {
                                ships[shipCount][k, 0] = xPos;
                                ships[shipCount][k, 1] = yPos;
                                yPos++;
                            }
                        }
                    }
                    while (CheckSet(ships[shipCount], field) == false);
                    for(int k = 0; k < 4 - i; k++)
                    {
                        field.cells[ships[shipCount][k, 0], ships[shipCount][k, 1]].IsShip = true;
                    }
                    shipCount++;
                }
            }
        }

        public void Set(Cursor cursor, Field field)
        {
            if (shipSetting == false)
            {
                field.cells[0, 0].IsShip = true;

                shipBeginPos[0] = cursor.GetPos()[1];
                shipBeginPos[1] = cursor.GetPos()[0];
                if (CheckSet(new int[,] { { cursor.GetPos()[0], cursor.GetPos()[1] } }, field))
                {
                    field.cells[shipBeginPos[0], shipBeginPos[1]].IsShip = true;
                    shipSetting = true;
                }
            }
            else
            {
                field.cells[0, 0].IsShip = false;

                int yEnd = cursor.GetPos()[1];
                int xEnd = cursor.GetPos()[0];
                if (CheckSet(new int[,] { { yEnd, xEnd } }, field))
                {
                    field.cells[yEnd, xEnd].IsShip = true;

                    //int shipLength = shipBeginPos[0] == yEnd ? xEnd - shipBeginPos[1] : yEnd - shipBeginPos[0];
                    //if (shipLength < 0)
                    //    shipLength = -shipLength;
                    //if (shipLength++ > 4 || shipLengths[shipLength] == 0)
                    //{
                    //    shipSetting = false;
                    //    return;
                    //}
                    //ships[shipCount] = new int[shipLength, 2];
                    //for(int i = 0; i < shipLength; i++)
                    //{
                    //    if (shipBeginPos[0] == yEnd)
                    //    {
                    //        ships[shipCount][i, 0] = yEnd;
                    //        ships[shipCount][i, 1] = xEnd - shipBeginPos[1] > 0 ? shipBeginPos[1]++ : shipBeginPos[1]--;
                    //    }
                    //    else
                    //    {
                    //        ships[shipCount][i, 0] = xEnd;
                    //        ships[shipCount][i, 1] = yEnd - shipBeginPos[0] > 0 ? shipBeginPos[0]++ : shipBeginPos[0]--;
                    //    }
                    //}

                    //for (int i = 0; i < shipLength; i++)
                    //{
                    //    field.cells[ships[shipCount][i, 0], ships[shipCount][i, 1]].IsShip = true;
                    //}

                    //shipLengths[shipLength]--;
                    shipCount++;
                    shipSetting = false;
                }
            }
        }

        private bool CheckSet(int[,] ship, Field field)
        {
            for (int i = 0; i < (ship.Length / 2 == 1? 1 : 2); i++)
            {
                int idx;
                if (i == 0)
                    idx = 0;
                else
                    idx = ship.Length / 2 - 1;

                if (ship[idx, 0] >= 10 || ship[idx, 0] < 0 || ship[idx, 1] >= 10 || ship[idx, 1] < 0)
                    return false;

                int xPos = ship[idx, 0] - 1;
                int yPos = ship[idx, 1] - 1;

                if (yPos >= 0)
                {
                    if (xPos >= 0 && field.cells[xPos, yPos].IsShip == true)
                        return false;

                    xPos = ship[idx, 0];
                    if (field.cells[xPos, yPos].IsShip == true)
                        return false;

                    xPos = ship[idx, 0] + 1;
                    if (xPos < 10 && field.cells[xPos, yPos].IsShip == true)
                        return false;
                }

                xPos = ship[idx, 0] - 1;
                yPos = ship[idx, 1];
                if (xPos >= 0 && field.cells[xPos, yPos].IsShip == true)
                    return false;

                xPos = ship[idx, 0];
                if (field.cells[xPos, yPos].IsShip == true)
                    return false;

                xPos = ship[idx, 0] + 1;
                if (xPos < 10 && field.cells[xPos, yPos].IsShip == true)
                    return false;


                xPos = ship[idx, 0] - 1;
                yPos = ship[idx, 1] + 1;

                if (yPos < 10)
                {
                    if (xPos >= 0 && field.cells[xPos, yPos].IsShip == true)
                        return false;

                    xPos = ship[idx, 0];
                    if (field.cells[xPos, yPos].IsShip == true)
                        return false;

                    xPos = ship[idx, 0] + 1;
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
                    return true;
                }
                else
                    return false;
            }
        }

        public bool RandomShot(Field field)
        {
            var random = new Random();

            if (isDamagedShip == true)
            {
                if (damageCountOfShip == 1)
                {
                    int[,] shotVariants = new int[,] { { yPosOfFirstHit - 1, xPosOfFirstHit }, { yPosOfFirstHit + 1, xPosOfFirstHit },
                        { yPosOfFirstHit, xPosOfFirstHit - 1 }, { yPosOfFirstHit, xPosOfFirstHit + 1 } };
                    do
                    {
                        int element = random.Next(0, 4);
                        xPosOfShot = shotVariants[element, 1];
                        yPosOfShot = shotVariants[element, 0];
                    }
                    while (yPosOfShot < 0 || xPosOfShot < 0 || yPosOfShot > 9 || xPosOfShot > 9 || field.cells[yPosOfShot, xPosOfShot].IsShoted == true);
                }
                else
                {
                    yPosOfShot = yPosOfFirstHit;
                    xPosOfShot = xPosOfFirstHit;
                    int changer;
                    do
                        changer = random.Next(-1, 2);
                    while (changer == 0);

                    if(xPosOfFirstHit == xPosOfSecondHit)
                    {
                        do
                        {
                            yPosOfShot += changer;
                            if (yPosOfShot == 9 || yPosOfShot == 0 || field.cells[yPosOfShot, xPosOfShot].IsShoted == true &&
                                field.cells[yPosOfShot, xPosOfShot].IsShip == false)
                                changer = -changer;
                        }
                        while (field.cells[yPosOfShot, xPosOfShot].IsShoted == true);
                    }
                    else
                    {
                        do
                        {
                            xPosOfShot += changer;
                            if (xPosOfShot == 9 || xPosOfShot == 0 || field.cells[yPosOfShot, xPosOfShot].IsShoted == true &&
                                field.cells[yPosOfShot, xPosOfShot].IsShip == false)
                                changer = -changer;
                        }
                        while (field.cells[yPosOfShot, xPosOfShot].IsShoted == true);
                    }
                }
            }
            else
            {
                do
                {
                    xPosOfShot = random.Next() % 10;
                    yPosOfShot = random.Next() % 10;
                }
                while (field.cells[yPosOfShot, xPosOfShot].IsShoted == true);
            }

            field.cells[yPosOfShot, xPosOfShot].IsShoted = true;
            if (field.cells[yPosOfShot, xPosOfShot].IsShip == true)
            {
                DrowingCheck(new int[] { yPosOfShot, xPosOfShot }, field);
                if(damageCountOfShip == 1)
                {
                    xPosOfFirstHit = xPosOfShot;
                    yPosOfFirstHit = yPosOfShot;
                }
                else if(damageCountOfShip == 2)
                {
                    xPosOfSecondHit = xPosOfShot;
                    yPosOfSecondHit = yPosOfShot;
                }
                return true;
            }
            else
                return false;
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
                    {
                        damageCountOfShip++;
                        isDamagedShip = true;
                        return;
                    }
                }
                SetDrowed(ships[count], field);
                isDamagedShip = false;
                damageCountOfShip = 0;
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