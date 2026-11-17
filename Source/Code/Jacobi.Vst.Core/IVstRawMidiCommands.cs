namespace Jacobi.Vst.Core
{
    /// <summary>Optional synchronous borrowed MIDI batch; high word is delta frames, low word is a short MIDI message.</summary>
    public interface IVstRawMidiCommands
    {
        /// <summary>Allocates bounded native storage on the plug-in control owner before processing.</summary>
        void PrepareMidiEvents(int capacity);
        /// <summary>Consumes count values without retaining managed storage or allocating individual events.</summary>
        bool ProcessMidiEvents(ulong[] events, int count, int frames);
    }
}
