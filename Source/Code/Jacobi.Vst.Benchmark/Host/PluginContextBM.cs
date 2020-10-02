using Jacobi.Vst.Host.Interop;

namespace Jacobi.Vst.Benchmark.Host
{
    internal class PluginContextBM
    {
        public void CreateContext()
        {
            VstPluginContext.Create()
        }
    }
}
