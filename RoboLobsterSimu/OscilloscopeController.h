#import <Cocoa/Cocoa.h>
//#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CoreMedia.h>
    //#import <QuickTime/QuickTime.h>
    //#import <QTKit/QTKit.h>
#import <CoreAudio/CoreAudio.h>
#import <AudioUnit/AudioUnit.h>

@class Waveforms;
@class OscilloscopeView;
@class AppDelegate;


@interface OscilloscopeController : NSViewController {
}

@property (readwrite) double proxGain;
@property (readwrite) double proxOffset;
@property (readwrite) double proxGainMax;

@property (readwrite)  long   samplingOffset;     //Sweep offset from origin in samples
@property (readwrite)  long   samplingTerminus;   //Sweep Terminus from origin in samples
@property (readwrite)  long   samplingMaximum;    //Duration of file in samples
@property (readwrite)  long   samplingDuration;   //Duration of Sweep in samples

@property (readwrite, nonatomic)  double samplingRate;       //SamplingRate in Hz
@property (readwrite, nonatomic)  long   numColumns;          //Number of columns in the display
@property (readwrite, nonatomic)  double sampsPerCol;        //Samples per Pixel

@property (readwrite)  double sweepOffset;        //Sweep offset from origin in Sec
@property (readwrite)  double sweepTerminus;      //Terminus of Sweep in Sec
@property (readwrite)  double sweepDuration;      //Duration of Sweep in Sec
@property (readwrite)  double sweepMaximum;       //Duration of file in Sec


extern long elapsed;
@property (readwrite) double index;
@property (readwrite)  int traceIDchosen;      //Duration of file in Sec

@property (readwrite,retain) NSMutableArray* AllTracesInfo;    //This is an array of traces
@property (readwrite,retain) NSMutableArray* IndividualTraceInfo;    //This is an array of traces


//@property (readwrite, getter=isDoInitAndScale)      BOOL doInitAndScale;
@property (readwrite)          BOOL assetInited;
@property (nonatomic, readwrite)          BOOL doInitAndScale;

@property (weak) IBOutlet NSSlider *sweepDurationSlider;

@property (weak) IBOutlet NSTextField *sweepDurationTextBox;

@property (weak) IBOutlet NSSlider *sweepOffsetSlider;

@property (weak) IBOutlet NSTextField *sweepOffsetTextBox;

@property (weak) IBOutlet NSTextField *traceGainTextBox;

@property (weak) IBOutlet NSTextField *traceOffsetTextBox;



@property (weak) IBOutlet NSSlider *traceOffsetSlider;

@property (weak) IBOutlet NSSlider *traceGainSlider;

@property (weak) IBOutlet NSTextField *cellNameTextBox; //cell Name
@property (weak) IBOutlet NSTextField *alphaTextBox;
@property (weak) IBOutlet NSTextField *sigmaTextBox;

@property (weak) IBOutlet NSPopUpButton *displayTraceID;

- (IBAction)changeSweepDuration:(id)sender;

- (IBAction)changeSweepOffset:(id)sender;

- (IBAction)changeTraceGain:(id)sender;

- (IBAction)changeTraceOffset:(id)sender;

- (IBAction)changeView:(id)sender;

- (void)beginSendingStuffToBeDraw;

//GraphicsViewParameters
- (void) updateSweepValue;

- (void) initScopeSweep;

- (void) scaleScopeSweep;
    //- (void) drawScopeSweep;//: (NSRect)rect;
- (BOOL) doInitAndScale;
    //- (void) setOscilloscopeView:(OscilloscopeView *)view;
- (void) setDoInitAndScale:(BOOL)flag;

- (IBAction)chooseTraceID:(id)sender;

- (IBAction) invertProxGraph: (id)sender;
@end
