using BenchmarkDotNet.Running;

namespace Jacobi.Vst.Benchmark.Plugin
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            // Host
            BenchmarkRunner.Run<Host.PluginContextBM>();
        }
    }
}
