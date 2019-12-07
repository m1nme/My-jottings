using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenHardwareMonitor.Hardware;
namespace Get_CPU_Temp5
{
    class Program
    {
        public enum HT
        {
            Mainboard = 0,
            SuperIO = 1,
            CPU = 2,
            GpuNvidia = 3,
            GpuAti = 4,
            TBalancer = 5,
            Heatmaster = 6,
            HDD = 7,
        }
        public class UpdateVisitor : IVisitor
        {
            public void VisitComputer(IComputer computer)
            {
                computer.Traverse(this);
            }
            public void VisitHardware(IHardware hardware)
            {
                hardware.Update();
                foreach (IHardware subHardware in hardware.SubHardware) subHardware.Accept(this);
            }
            public void VisitSensor(ISensor sensor) { }
            public void VisitParameter(IParameter parameter) { }
        }
        static bool TestSystem(Computer computer,int[] HType)
        {          
            bool flag = false;
            for (int i = 0; i < computer.Hardware.Length; i++)
            {
                if (computer.Hardware[i].HardwareType == HardwareType.Mainboard)
                {
                    Console.WriteLine("Mainboard YES");
                    flag = true;
                    HType[i] = 0;
                }
                if (computer.Hardware[i].HardwareType == HardwareType.SuperIO)
                {
                    Console.WriteLine("SuperIO  YES");
                    flag = true;
                    HType[i] = 1;
                }           
                if (computer.Hardware[i].HardwareType == HardwareType.CPU)
                {
                    Console.WriteLine("CPU YES");
                    flag = true;
                    HType[i] = 2;                  
                }
                if (computer.Hardware[i].HardwareType == HardwareType.GpuAti)
                {
                    Console.WriteLine("GpuAti YES");
                    flag = true;
                    HType[i] = 4;
                }
                if (computer.Hardware[i].HardwareType == HardwareType.GpuNvidia)
                {
                    Console.WriteLine("GpuNvidia YES");
                    flag = true;
                    HType[i] = 3;
                }
                if (computer.Hardware[i].HardwareType == HardwareType.TBalancer)
                {
                    Console.WriteLine("TBalancer   YES");
                    flag = true;
                    HType[i] = 5;
                }
                if (computer.Hardware[i].HardwareType == HardwareType.Heatmaster)
                {
                    Console.WriteLine("Heatmaster    YES");
                    flag = true;
                    HType[i] = 6;
                }             
                if (computer.Hardware[i].HardwareType == HardwareType.HDD)
                {
                    Console.WriteLine("HDD     YES");
                    flag = true;
                    HType[i] = 7;
                }
            }            
            return flag;
        }
        static bool cpuinfo(Computer computer)
        {
            bool flag = false;
            for (int i = 0; i < computer.Hardware.Length; i++)
            {
                for (int j = 0; j < computer.Hardware[i].Sensors.Length; j++)
                {
                    if (computer.Hardware[i].Sensors[j].SensorType == SensorType.Temperature)
                    {
                        Console.WriteLine(computer.Hardware[i].Sensors[j].Name + "_" + "Temperature" + ":" + computer.Hardware[i].Sensors[j].Value.ToString() + "\r");
                        flag = true;
                    }
                    if (computer.Hardware[i].Sensors[j].SensorType == SensorType.Voltage)
                    {
                        Console.WriteLine(computer.Hardware[i].Sensors[j].Name + "_" + "Voltage" + ":" + computer.Hardware[i].Sensors[j].Value.ToString() + "\r");
                        flag = true;
                    }
                    if (computer.Hardware[i].Sensors[j].SensorType == SensorType.Clock)
                    {
                        Console.WriteLine(computer.Hardware[i].Sensors[j].Name + "_" + "Clock " + ":" + computer.Hardware[i].Sensors[j].Value.ToString() + "\r");
                        flag = true;
                    }
                    if (computer.Hardware[i].Sensors[j].SensorType == SensorType.Load)
                    {
                        Console.WriteLine(computer.Hardware[i].Sensors[j].Name + "_" + "Load  " + ":" + computer.Hardware[i].Sensors[j].Value.ToString() + "\r");
                        flag = true;
                    }
                }
                /*
                if (computer.Hardware[i].HardwareType == HardwareType.CPU)
                {
                    for (int j = 0; j < computer.Hardware[i].Sensors.Length; j++)
                    {
                        if (computer.Hardware[i].Sensors[j].SensorType == SensorType.Load)
                        {
                            Console.WriteLine(computer.Hardware[i].Sensors[j].Name + ":" + computer.Hardware[i].Sensors[j].Value.ToString() + "\r");
                            flag = true;
                        }                           
                    }
                }
                */
            }
            /*
            for (int j = 0; j < computer.Hardware[i].Sensors.Length; j++)
           {
                if (computer.Hardware[1].Sensors[j].SensorType == SensorType.Temperature)
                {
                    Console.WriteLine(computer.Hardware[1].Sensors[j].Name + "_" + "Temperature" + ":" + computer.Hardware[i].Sensors[j].Value.ToString() + "\r");
                }                   
                if (computer.Hardware[1].Sensors[j].SensorType == SensorType.Voltage)
                {
                    Console.WriteLine(computer.Hardware[1].Sensors[j].Name + "_" + "Voltage" + ":" + computer.Hardware[i].Sensors[j].Value.ToString() + "\r");
                }
                if (computer.Hardware[1].Sensors[j].SensorType == SensorType.Clock)
                {
                    Console.WriteLine(computer.Hardware[1].Sensors[j].Name + "_"+ "Clock " + ":" + computer.Hardware[i].Sensors[j].Value.ToString() + "\r");
                }
                if (computer.Hardware[1].Sensors[j].SensorType == SensorType.Load)
                {
                    Console.WriteLine(computer.Hardware[1].Sensors[j].Name + "_" + "Load  " + ":" + computer.Hardware[i].Sensors[j].Value.ToString() + "\r");
                }
            }
            */
            return flag;
        }
        static void Main(string[] args)
        {
            UpdateVisitor updateVisitor = new UpdateVisitor();
            Computer computer = new Computer();
            computer.Open();
            computer.CPUEnabled = true;
            computer.GPUEnabled = true;
            computer.HDDEnabled = true;
            computer.RAMEnabled = true;
            computer.Accept(updateVisitor);
            bool flag = false;
            int[] HType = new int[computer.Hardware.Length];
            while (true)
            {
                flag = TestSystem(computer,HType);
                if (flag)
                    break;
            }     
            for(int i = 0; i < computer.Hardware.Length; i++)
            {
                Console.WriteLine(HType[i]);
            }
            for (int i = 0; i < computer.Hardware.Length; i++)
            {
                if(HType[i] == 2)
                {
                    while (true)
                    {
                        flag = cpuinfo(computer);
                        if (flag)
                            break;
                    }                
                }
            }
            computer.Close();
            string a;
            a = Console.ReadLine();
        }
    }
}