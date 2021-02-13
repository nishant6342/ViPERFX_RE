//
// Created by mart on 2/13/21.
//

#include "ProcessUnit_FX.h"
#include "util/AdaptiveBuffer_FPI32.h"

// ProcessUnit_FX::ProcessUnit_FX()

ProcessUnit_FX::ProcessUnit_FX() {
    AdaptiveBuffer_FPI32 *this_00;
    WaveBuffer_R32 *this_01;
    Convolver *this_02;
    VHE *this_03;
    ViPERDDC *this_04;
    SpectrumExtend *this_05;
    IIRFilter *this_06;
    ColorfulMusic *this_07;
    Reverberation *this_08;
    PlaybackGain *this_09;
    FETCompressor *this_10;
    DynamicSystem *this_11;
    ViPERBass *this_12;
    ViPERClarity *this_13;
    DiffSurround *this_14;
    Cure *this_15;
    AnalogX *pAVar1;
    TubeSimulator *pTVar2;
    SpeakerCorrection *this_16;
    SoftwareLimiter *pSVar3;
    float fVar4;
    float extraout_s0;

    Effect::Effect((Effect *)this);  // Parent class?
    this->field_0x0 = &PTR_command_000d0cf8;  // ?
    __android_log_print(4,"ViPER4Android_v2","Welcome to ViPER4Android driver[SQ]");
    __android_log_print(4,"ViPER4Android_v2","Current version is %d.%d.%d.%d %s",2,5,0,4,"Beautiful");
    this->field_0x68 = (undefined *)this;
    this->field_0x88 = 0;
    this->floatIntBuffer = new AdaptiveBuffer_FPI32(2,0x1000);
    this->waveBuffer = new WaveBuffer_R32(2,0x1000);
    this_02 = (Convolver *)operator_new(0x174);
    Convolver::Convolver(this_02);
    this->convolver = this_02;
    this_03 = (VHE *)operator_new(0x38);
    VHE::VHE(this_03);
    this->vhe = this_03;
    this_04 = (ViPERDDC *)operator_new(0x34);
    ViPERDDC::ViPERDDC(this_04);
    this->vddc = this_04;
    this_05 = (SpectrumExtend *)operator_new(0x118);
    SpectrumExtend::SpectrumExtend(this_05);
    this->spectrumExtend = this_05;
    this_06 = (IIRFilter *)operator_new(0x860);
    IIRFilter::IIRFilter(this_06,10);
    this->iirFilter = this_06;
    this_07 = (ColorfulMusic *)operator_new(0x6c);
    ColorfulMusic::ColorfulMusic(this_07);
    this->colorful = this_07;
    this_08 = (Reverberation *)operator_new(0x2ec);
    Reverberation::Reverberation(this_08);
    this->reverb = this_08;
    this_09 = (PlaybackGain *)operator_new(0x78);
    PlaybackGain::PlaybackGain(this_09);
    this->playbackGain = this_09;
    this_10 = (FETCompressor *)operator_new(0xb0);
    FETCompressor::FETCompressor(this_10);
    this->fetCompressor = this_10;
    this_11 = (DynamicSystem *)operator_new(0x138);
    DynamicSystem::DynamicSystem(this_11);
    this->dynamicSystem = this_11;
    this_12 = (ViPERBass *)operator_new(0x2c);
    ViPERBass::ViPERBass(this_12);
    this->vbass = this_12;
    this_13 = (ViPERClarity *)operator_new(0xe0);
    ViPERClarity::ViPERClarity(this_13);
    this->vclarity = this_13;
    this_14 = (DiffSurround *)operator_new(0x14);
    DiffSurround::DiffSurround(this_14);
    this->diffSurround = this_14;
    this_15 = (Cure *)operator_new(0x50);
    Cure::Cure(this_15);
    this->cure = this_15;
    pAVar1 = (AnalogX *)operator_new(0x164);
    AnalogX::AnalogX(pAVar1);
    this->analogx = pAVar1;
    pTVar2 = (TubeSimulator *)operator_new(0xc);
    TubeSimulator::TubeSimulator(pTVar2);
    this->tubeSim = pTVar2;
    this_16 = (SpeakerCorrection *)operator_new(0xe0);
    SpeakerCorrection::SpeakerCorrection(this_16);
    this->speakerCorrection = this_16;
    pSVar3 = (SoftwareLimiter *)operator_new(0xc28);
    SoftwareLimiter::SoftwareLimiter(pSVar3);
    this->softLimit1 = pSVar3;
    pSVar3 = (SoftwareLimiter *)operator_new(0xc28);
    fVar4 = (float)SoftwareLimiter::SoftwareLimiter(pSVar3);
    this->softLimit2 = pSVar3;
    if (this->convolver != nullptr) {
        Convolver::SetEnable(this->convolver,false);
        Convolver::SetSamplingRate(this->convolver,this->samplerate);
        fVar4 = (float)Convolver::Reset(this->convolver);
    }
    if (this->vhe != nullptr) {
        VHE::SetEnable(this->vhe,false);
        VHE::SetSamplingRate(this->vhe,this->samplerate);
        fVar4 = (float)VHE::Reset(this->vhe);
    }
    if (this->vddc != nullptr) {
        ViPERDDC::SetEnable(this->vddc,false);
        ViPERDDC::SetSamplingRate(this->vddc,this->samplerate);
        fVar4 = (float)ViPERDDC::Reset(this->vddc);
    }
    if (this->spectrumExtend != nullptr) {
        SpectrumExtend::SetEnable(this->spectrumExtend,false);
        SpectrumExtend::SetSamplingRate(this->spectrumExtend,this->samplerate);
        fVar4 = (float)SpectrumExtend::SetReferenceFrequency(this->spectrumExtend,0x1db0);
        SpectrumExtend::SetExciter(this->spectrumExtend,fVar4);
        fVar4 = (float)SpectrumExtend::Reset();
    }
    if (this->iirFilter != nullptr) {
        IIRFilter::SetEnable(this->iirFilter,false);
        IIRFilter::SetSamplingRate(this->iirFilter,this->samplerate);
        fVar4 = (float)IIRFilter::Reset(this->iirFilter);
    }
    if (this->colorful != nullptr) {
        ColorfulMusic::SetEnable(this->colorful,false);
        ColorfulMusic::SetSamplingRate(this->colorful,this->samplerate);
        fVar4 = (float)ColorfulMusic::Reset(this->colorful);
    }
    if (this->reverb != nullptr) {
        Reverberation::SetEnable(this->reverb,false);
        Reverberation::SetSamplingRate(this->reverb,this->samplerate);
        fVar4 = (float)Reverberation::Reset(this->reverb);
    }
    if (this->playbackGain != nullptr) {
        PlaybackGain::SetEnable(this->playbackGain,false);
        PlaybackGain::SetSamplingRate(this->playbackGain,this->samplerate);
        PlaybackGain::Reset(this->playbackGain);
        fVar4 = extraout_s0;
    }
    if (this->fetCompressor != nullptr) {
        FETCompressor::SetParameter((int)this->fetCompressor,fVar4);
        FETCompressor::SetSamplingRate(this->fetCompressor,this->samplerate);
        FETCompressor::Reset(this->fetCompressor);
    }
    if (this->dynamicSystem != nullptr) {
        DynamicSystem::SetEnable(this->dynamicSystem,false);
        DynamicSystem::SetSamplingRate(this->dynamicSystem,this->samplerate);
        DynamicSystem::Reset(this->dynamicSystem);
    }
    if (this->vbass != nullptr) {
        ViPERBass::SetEnable(this->vbass,false);
        ViPERBass::SetSamplingRate(this->vbass,this->samplerate);
        ViPERBass::Reset();
    }
    if (this->vclarity != nullptr) {
        ViPERClarity::SetEnable(this->vclarity,false);
        ViPERClarity::SetSamplingRate(this->vclarity,this->samplerate);
        ViPERClarity::Reset(this->vclarity);
    }
    if (this->diffSurround != nullptr) {
        DiffSurround::SetEnable(this->diffSurround,false);
        DiffSurround::SetSamplingRate(this->diffSurround,this->samplerate);
        DiffSurround::Reset(this->diffSurround);
    }
    if (this->cure != nullptr) {
        Cure::SetEnable(this->cure,false);
        Cure::SetSamplingRate(this->cure,this->samplerate);
        Cure::Reset(this->cure);
    }
    pTVar2 = this->tubeSim;
    if (pTVar2 != nullptr) {
        pTVar2->field_0x8 = false;
        TubeSimulator::Reset(pTVar2);
    }
    pAVar1 = this->analogx;
    if (pAVar1 != nullptr) {
        pAVar1->enabled = false;
        AnalogX::SetSamplingRate(pAVar1,this->samplerate);
        AnalogX::SetProcessingModel(this->analogx,0);
        AnalogX::Reset(this->analogx);
    }
    if (this->speakerCorrection != nullptr) {
        SpeakerCorrection::SetEnable(this->speakerCorrection,false);
        SpeakerCorrection::SetSamplingRate(this->speakerCorrection,this->samplerate);
        SpeakerCorrection::Reset(this->speakerCorrection);
    }
    if (this->softLimit1 != nullptr) {
        SoftwareLimiter::ResetLimiter(this->softLimit1);
    }
    if (this->softLimit2 != nullptr) {
        SoftwareLimiter::ResetLimiter(this->softLimit2);
    }
    if (((((((this->floatIntBuffer == nullptr) || (this->waveBuffer == nullptr)) ||
            (this->softLimit1 == nullptr)) ||
           (((this->softLimit2 == nullptr || (this->convolver == nullptr)) ||
             ((this->vhe == nullptr || ((this->vddc == nullptr || (this->spectrumExtend == nullptr)))))))) ||
          ((this->iirFilter == nullptr ||
            (((this->colorful == nullptr || (this->reverb == nullptr)) || (this->playbackGain == nullptr)))))) ||
         (((this->fetCompressor == nullptr || (this->vbass == nullptr)) ||
           (((this->vclarity == nullptr || ((this->diffSurround == nullptr || (this->dynamicSystem == nullptr))))
             || (this->cure == nullptr)))))) ||
        (((this->tubeSim == nullptr || (this->analogx == nullptr)) || (this->speakerCorrection == nullptr)))) {
        *(undefined *)&this->field_0x78 = 0;
    }
    else {
        *(undefined *)&this->field_0x78 = 1;
    }
    this->field_0xd8 = 0x2000000;
    this->field_0xdc = 0x2000000;
    this->field_0x70 = 0;
    this->field_0xe0 = 0x2000000;
    *(undefined *)&this->field_0x79 = 0;
    *(undefined *)&this->field_0x7a = 0;
    this->field_0x7c = 0;
    *(undefined *)&this->field_0x6c = 0;
    return this;
}



// ProcessUnit_FX::~ProcessUnit_FX()

ProcessUnit_FX::~ProcessUnit_FX() {
    AdaptiveBuffer_FPI32 *this_00;
    WaveBuffer_R32 *this_01;
    Convolver *this_02;
    VHE *this_03;
    ViPERDDC *this_04;
    SpectrumExtend *this_05;
    IIRFilter *this_06;
    ColorfulMusic *pCVar1;
    Reverberation *pRVar2;
    FETCompressor *this_07;
    ViPERBass *this_08;
    ViPERClarity *this_09;
    DiffSurround *this_10;
    Cure *this_11;
    Harmonic *this_12;
    AnalogX *pAVar3;

    this_00 = this->floatIntBuffer;
    this->field_0x0 = &PTR_command_000d0cf8;
    if (this_00 != nullptr) {
        AdaptiveBuffer_FPI32::~AdaptiveBuffer_FPI32(this_00);
        operator_delete(this_00);
    }
    this_01 = this->waveBuffer;
    if (this_01 != nullptr) {
        WaveBuffer_R32::~WaveBuffer_R32(this_01);
        operator_delete(this_01);
    }
    this_02 = this->convolver;
    if (this_02 != nullptr) {
        Convolver::~Convolver(this_02);
        operator_delete(this_02);
    }
    this_03 = this->vhe;
    if (this_03 != nullptr) {
        VHE::~VHE(this_03);
        operator_delete(this_03);
    }
    this_04 = this->vddc;
    if (this_04 != nullptr) {
        ViPERDDC::~ViPERDDC(this_04);
        operator_delete(this_04);
    }
    this_05 = this->spectrumExtend;
    if (this_05 != nullptr) {
        SpectrumExtend::~SpectrumExtend(this_05);
        operator_delete(this_05);
    }
    this_06 = this->iirFilter;
    if (this_06 != nullptr) {
        IIRFilter::~IIRFilter(this_06);
        operator_delete(this_06);
    }
    pCVar1 = this->colorful;
    if (pCVar1 != nullptr) {
        TimeConstDelay::~TimeConstDelay((TimeConstDelay *)&pCVar1->field_0x34);
        TimeConstDelay::~TimeConstDelay((TimeConstDelay *)&pCVar1->field_0x28);
        operator_delete(pCVar1);
    }
    pRVar2 = this->reverb;
    if (pRVar2 != nullptr) {
        CRevModel::~CRevModel(&pRVar2->field_0x14);
        operator_delete(pRVar2);
    }
    if (this->playbackGain != nullptr) {
        operator_delete(this->playbackGain);
    }
    this_07 = this->fetCompressor;
    if (this_07 != nullptr) {
        FETCompressor::~FETCompressor(this_07);
        operator_delete(this_07);
    }
    if (this->dynamicSystem != nullptr) {
        operator_delete(this->dynamicSystem);
    }
    this_08 = this->vbass;
    if (this_08 != nullptr) {
        ViPERBass::~ViPERBass(this_08);
        operator_delete(this_08);
    }
    this_09 = this->vclarity;
    if (this_09 != nullptr) {
        ViPERClarity::~ViPERClarity(this_09);
        operator_delete(this_09);
    }
    this_10 = this->diffSurround;
    if (this_10 != nullptr) {
        DiffSurround::~DiffSurround(this_10);
        operator_delete(this_10);
    }
    this_11 = this->cure;
    if (this_11 != nullptr) {
        Cure::~Cure(this_11);
        operator_delete(this_11);
    }
    if (this->tubeSim != nullptr) {
        operator_delete(this->tubeSim);
    }
    pAVar3 = this->analogx;
    if (pAVar3 != nullptr) {
        this_12 = (Harmonic *)&pAVar3->field_0xc0;
        do {
            this_12 = this_12 + -1;
            Harmonic::~Harmonic(this_12);
        } while (&pAVar3->field_0x48 != this_12);
        operator_delete(pAVar3);
    }
    if (this->speakerCorrection != nullptr) {
        operator_delete(this->speakerCorrection);
    }
    if (this->softLimit1 != nullptr) {
        operator_delete(this->softLimit1);
    }
    if (this->softLimit2 != nullptr) {
        operator_delete(this->softLimit2);
    }
    Effect::~Effect((Effect *)this);
    return this;
}



// ProcessUnit_FX::ResetAllEffects()

void ProcessUnit_FX::ResetAllEffects() {
    if (this->convolver != nullptr) {
        Convolver::SetSamplingRate(this->convolver,this->samplerate);
    }
    if (this->vhe != nullptr) {
        VHE::SetSamplingRate(this->vhe,this->samplerate);
    }
    if (this->vddc != nullptr) {
        ViPERDDC::SetSamplingRate(this->vddc,this->samplerate);
    }
    if (this->spectrumExtend != nullptr) {
        SpectrumExtend::SetSamplingRate(this->spectrumExtend,this->samplerate);
    }
    if (this->iirFilter != nullptr) {
        IIRFilter::SetSamplingRate(this->iirFilter,this->samplerate);
    }
    if (this->colorful != nullptr) {
        ColorfulMusic::SetSamplingRate(this->colorful,this->samplerate);
    }
    if (this->reverb != nullptr) {
        Reverberation::SetSamplingRate(this->reverb,this->samplerate);
    }
    if (this->playbackGain != nullptr) {
        PlaybackGain::SetSamplingRate(this->playbackGain,this->samplerate);
    }
    if (this->fetCompressor != nullptr) {
        FETCompressor::SetSamplingRate(this->fetCompressor,this->samplerate);
    }
    if (this->dynamicSystem != nullptr) {
        DynamicSystem::SetSamplingRate(this->dynamicSystem,this->samplerate);
    }
    if (this->vbass != nullptr) {
        ViPERBass::SetSamplingRate(this->vbass,this->samplerate);
    }
    if (this->vclarity != nullptr) {
        ViPERClarity::SetSamplingRate(this->vclarity,this->samplerate);
    }
    if (this->diffSurround != nullptr) {
        DiffSurround::SetSamplingRate(this->diffSurround,this->samplerate);
    }
    if (this->cure != nullptr) {
        Cure::SetSamplingRate(this->cure,this->samplerate);
    }
    if (this->analogx != nullptr) {
        AnalogX::SetSamplingRate(this->analogx,this->samplerate);
    }
    if (this->speakerCorrection != nullptr) {
        SpeakerCorrection::SetSamplingRate(this->speakerCorrection,this->samplerate);
    }
    if (this->floatIntBuffer != nullptr) {
        AdaptiveBuffer_FPI32::FlushBuffer(this->floatIntBuffer);
    }
    if (this->waveBuffer != nullptr) {
        WaveBuffer_R32::Reset(this->waveBuffer);
    }
    if (this->convolver != nullptr) {
        Convolver::Reset(this->convolver);
    }
    if (this->vhe != nullptr) {
        VHE::Reset(this->vhe);
    }
    if (this->vddc != nullptr) {
        ViPERDDC::Reset(this->vddc);
    }
    if (this->spectrumExtend != nullptr) {
        SpectrumExtend::Reset();
    }
    if (this->iirFilter != nullptr) {
        IIRFilter::Reset(this->iirFilter);
    }
    if (this->colorful != nullptr) {
        ColorfulMusic::Reset(this->colorful);
    }
    if (this->reverb != nullptr) {
        Reverberation::Reset(this->reverb);
    }
    if (this->playbackGain != nullptr) {
        PlaybackGain::Reset(this->playbackGain);
    }
    if (this->fetCompressor != nullptr) {
        FETCompressor::Reset(this->fetCompressor);
    }
    if (this->dynamicSystem != nullptr) {
        DynamicSystem::Reset(this->dynamicSystem);
    }
    if (this->vbass != nullptr) {
        ViPERBass::Reset();
    }
    if (this->vclarity != nullptr) {
        ViPERClarity::Reset(this->vclarity);
    }
    if (this->diffSurround != nullptr) {
        DiffSurround::Reset(this->diffSurround);
    }
    if (this->cure != nullptr) {
        Cure::Reset(this->cure);
    }
    if (this->tubeSim != nullptr) {
        TubeSimulator::Reset(this->tubeSim);
    }
    if (this->analogx != nullptr) {
        AnalogX::Reset(this->analogx);
    }
    if (this->speakerCorrection != nullptr) {
        SpeakerCorrection::Reset(this->speakerCorrection);
    }
    if (this->softLimit1 != nullptr) {
        SoftwareLimiter::ResetLimiter(this->softLimit1);
    }
    if (this->softLimit2 == nullptr) {
        return;
    }
    SoftwareLimiter::ResetLimiter(this->softLimit2);
    return;
}



// ProcessUnit_FX::DispatchCommand(int, int, int, int, int, int, signed char*)

void ProcessUnit_FX::DispatchCommand(int param_1,int param_2,int param_3,int param_4,int param_5,
                                     int param_6,signed *param_7) {
    bool bVar1;
    signed *psVar2;
    PlaybackGain *this_00;
    DynamicSystem *this_01;
    TubeSimulator *pTVar3;
    SpeakerCorrection *this_02;
    SoftwareLimiter *pSVar4;
    uint uVar5;
    float fVar6;
    int iVar7;
    AdaptiveBuffer_FPI32 *pAVar8;
    WaveBuffer_R32 *pWVar9;
    Convolver *pCVar10;
    VHE *pVVar11;
    ViPERDDC *pVVar12;
    SpectrumExtend *pSVar13;
    IIRFilter *pIVar14;
    ColorfulMusic *pCVar15;
    Reverberation *pRVar16;
    FETCompressor *pFVar17;
    ViPERBass *pVVar18;
    ViPERClarity *pVVar19;
    DiffSurround *pDVar20;
    Cure *pCVar21;
    Harmonic *pHVar22;
    AnalogX *pAVar23;
    float in_s0;
    float fVar24;
    undefined4 uVar25;
    undefined4 uVar26;
    undefined4 uVar27;
    char acStack292 [256];
    int local_24;

    iVar7 = param_2;
    if (param_2 != 0) {
        iVar7 = 1;
    }
    local_24 = __stack_chk_guard;
    if (param_1 == 0x10033) {
        if (param_2 == 0) {
            this->field_0xdc = 0x2000000;
            this->field_0xe0 = 0x2000000;
        }
        else {
            if (param_2 < 0) {
                fVar24 = 9.403955e-38;
                fVar6 = ROUND((1.0 - ABS((float)(longlong)param_2 / 100.0)) * 3.355443e+07 + 0.5);
            }
            else {
                fVar6 = 9.403955e-38;
                fVar24 = ROUND((1.0 - ABS((float)(longlong)param_2 / 100.0)) * 3.355443e+07 + 0.5);
            }
            this->field_0xdc = fVar24;
            this->field_0xe0 = fVar6;
        }
        goto LAB_00071250;
    }
    bVar1 = SUB41(iVar7,0);
    if (param_1 < 0x10034) {
        if (param_1 == 0x10016) {
            if (this->diffSurround != nullptr) {
                DiffSurround::SetDelayTime(this->diffSurround,in_s0);
            }
            goto LAB_00071250;
        }
        if (0x10016 < param_1) {
            if (param_1 == 0x10024) {
                if (this->dynamicSystem != nullptr) {
                    DynamicBass::~ZN13DynamicSystem11SetSideGainEff
                    ((DynamicBass *)this->dynamicSystem,(int)((float)(longlong)param_2 / 100.0),
                            (int)((float)(longlong)param_3 / 100.0));
                }
                goto LAB_00071250;
            }
            if (0x10024 < param_1) {
                if (param_1 == 0x1002b) {
                    if (this->vclarity != nullptr) {
                        ViPERClarity::SetProcessMode(this->vclarity,param_2);
                    }
                    goto LAB_00071250;
                }
                if (param_1 < 0x1002c) {
                    if (param_1 == 0x10027) {
                        if (this->vbass != nullptr) {
                            ViPERBass::SetProcessMode(this->vbass,param_2);
                        }
                    }
                    else {
                        if (param_1 < 0x10028) {
                            if (param_1 == 0x10025) {
                                if (this->dynamicSystem != nullptr) {
                                    DynamicBass::~ZN13DynamicSystem11SetBassGainEf
                                    ((DynamicBass *)this->dynamicSystem,
                                            (int)((float)(longlong)param_2 / 100.0));
                                }
                            }
                            else {
                                if ((param_1 == 0x10026) && (this->vbass != nullptr)) {
                                    ViPERBass::SetEnable(this->vbass,bVar1);
                                }
                            }
                        }
                        else {
                            if (param_1 == 0x10029) {
                                if (this->vbass != nullptr) {
                                    ViPERBass::SetBassFactor(in_s0);
                                }
                            }
                            else {
                                if (param_1 < 0x1002a) {
                                    if (this->vbass != nullptr) {
                                        ViPERBass::SetSpeaker((int)this->vbass);
                                    }
                                }
                                else {
                                    if (this->vclarity != nullptr) {
                                        ViPERClarity::SetEnable(this->vclarity,bVar1);
                                    }
                                }
                            }
                        }
                    }
                    goto LAB_00071250;
                }
                if (param_1 == 0x1002f) {
                    pTVar3 = this->tubeSim;
                    if (pTVar3 != nullptr) {
                        if ((pTVar3->field_0x8 == false) && (iVar7 != 0)) {
                            TubeSimulator::Reset(pTVar3);
                        }
                        pTVar3->field_0x8 = bVar1;
                    }
                    goto LAB_00071250;
                }
                if (param_1 < 0x10030) {
                    if (param_1 == 0x1002d) {
                        if (this->cure != nullptr) {
                            Cure::SetEnable(this->cure,bVar1);
                        }
                    }
                    else {
                        if (param_1 < 0x1002e) {
                            if (this->vclarity != nullptr) {
                                ViPERClarity::SetClarity(this->vclarity,in_s0);
                            }
                        }
                        else {
                            pCVar21 = this->cure;
                            if (pCVar21 != nullptr) {
                                if (param_2 == 1) {
                                    Crossfeed::~ZN4Cure9SetPresetEj((Crossfeed *)pCVar21,0x3c02bc);
                                }
                                else {
                                    if (param_2 == 2) {
                                        Crossfeed::~ZN4Cure9SetPresetEj((Crossfeed *)pCVar21,0x2d02bc);
                                    }
                                    else {
                                        if (param_2 == 0) {
                                            Crossfeed::~ZN4Cure9SetPresetEj((Crossfeed *)pCVar21,0x5f028a);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    goto LAB_00071250;
                }
                if (param_1 == 0x10031) {
                    pAVar23 = this->analogx;
                    if (pAVar23 != nullptr) {
                        if (param_2 == 1) {
                            AnalogX::SetProcessingModel(pAVar23,1);
                        }
                        else {
                            if (param_2 == 2) {
                                AnalogX::SetProcessingModel(pAVar23,2);
                            }
                            else {
                                if (param_2 == 0) {
                                    AnalogX::SetProcessingModel(pAVar23,0);
                                }
                            }
                        }
                    }
                    goto LAB_00071250;
                }
                if (param_1 < 0x10032) {
                    pAVar23 = this->analogx;
                    if (pAVar23 != nullptr) {
                        if ((pAVar23->enabled == false) && (iVar7 != 0)) {
                            AnalogX::Reset(pAVar23);
                        }
                        pAVar23->enabled = bVar1;
                    }
                    goto LAB_00071250;
                }
                LAB_00071ac4:
                if (param_2 == 100) {
                    this->field_0xd8 = 0x2000000;
                }
                else {
                    this->field_0xd8 = ROUND(((float)(longlong)param_2 / 100.0) * 3.355443e+07 + 0.5);
                }
                goto LAB_00071250;
            }
            if (param_1 == 0x1001d) {
                LAB_00071f48:
                if (this->playbackGain != nullptr) {
                    PlaybackGain::SetEnable(this->playbackGain,bVar1);
                }
                goto LAB_00071250;
            }
            if (0x1001d < param_1) {
                if (param_1 == 0x10020) {
                    LAB_00071644:
                    if (this->playbackGain != nullptr) {
                        PlaybackGain::SetMaxGainFactor(this->playbackGain,in_s0);
                    }
                    goto LAB_00071250;
                }
                if (0x10020 < param_1) {
                    if (param_1 == 0x10022) {
                        if (this->dynamicSystem != nullptr) {
                            DynamicBass::~ZN13DynamicSystem10SetXCoeffsEjj
                            ((DynamicBass *)this->dynamicSystem,param_2,param_3);
                        }
                    }
                    else {
                        if (param_1 < 0x10023) {
                            if (this->dynamicSystem != nullptr) {
                                DynamicSystem::SetEnable(this->dynamicSystem,bVar1);
                            }
                        }
                        else {
                            if (this->dynamicSystem != nullptr) {
                                DynamicBass::~ZN13DynamicSystem10SetYCoeffsEjj
                                ((DynamicBass *)this->dynamicSystem,param_2,param_3);
                            }
                        }
                    }
                    goto LAB_00071250;
                }
                if (param_1 == 0x1001e) {
                    LAB_00071b1c:
                    if (this->playbackGain != nullptr) {
                        PlaybackGain::SetRatio(this->playbackGain,in_s0);
                    }
                    goto LAB_00071250;
                }
                if (param_1 != 0x1001f) goto LAB_00071250;
                LAB_00071564:
                if (this->playbackGain != nullptr) {
                    PlaybackGain::SetVolume(this->playbackGain,in_s0);
                }
                goto LAB_00071250;
            }
            if (param_1 == 0x10019) {
                LAB_00071918:
                if (this->reverb != nullptr) {
                    Reverberation::SetWidth(this->reverb,(int)((float)(longlong)param_2 / 100.0));
                }
                goto LAB_00071250;
            }
            if (param_1 < 0x1001a) {
                if (param_1 != 0x10017) {
                    if (param_1 != 0x10018) goto LAB_00071250;
                    goto LAB_00071840;
                }
                goto LAB_00071900;
            }
            if (param_1 != 0x1001b) {
                if (param_1 < 0x1001c) goto LAB_000707e4;
                goto LAB_00071608;
            }
            goto LAB_00071b78;
        }
        if (param_1 == 0x10008) {
            if (this->vhe != nullptr) {
                VHE::SetEnable(this->vhe,bVar1);
            }
            goto LAB_00071250;
        }
        if (0x10008 < param_1) {
            if (param_1 == 0x1000f) {
                LAB_00071d64:
                if (this->iirFilter != nullptr) {
                    IIRFilter::SetEnable(this->iirFilter,bVar1);
                }
                goto LAB_00071250;
            }
            if (param_1 < 0x10010) {
                if (param_1 == 0x1000b) {
                    if (((this->vddc != nullptr) && (param_6 - 1U < 0x7f)) && (param_7 != nullptr)) {
                        ViPERDDC::SetCoeffs(this->vddc,param_6,(float *)param_7,(float *)(param_7 + param_6 * 4)
                        );
                    }
                }
                else {
                    if (param_1 < 0x1000c) {
                        if (param_1 == 0x10009) {
                            if (this->vhe != nullptr) {
                                VHE::SetEffectLevel(this->vhe,param_2);
                            }
                        }
                        else {
                            if ((param_1 == 0x1000a) && (this->vddc != nullptr)) {
                                ViPERDDC::SetEnable(this->vddc,bVar1);
                            }
                        }
                    }
                    else {
                        if (param_1 == 0x1000d) {
                            if (this->spectrumExtend != nullptr) {
                                SpectrumExtend::SetReferenceFrequency(this->spectrumExtend,param_2);
                            }
                        }
                        else {
                            if (param_1 < 0x1000e) {
                                if (this->spectrumExtend != nullptr) {
                                    SpectrumExtend::SetEnable(this->spectrumExtend,bVar1);
                                }
                            }
                            else {
                                if (this->spectrumExtend != nullptr) {
                                    SpectrumExtend::SetExciter(this->spectrumExtend,in_s0);
                                }
                            }
                        }
                    }
                }
                goto LAB_00071250;
            }
            if (param_1 == 0x10012) {
                if (this->colorful != nullptr) {
                    Stereo3DSurround::~ZN13ColorfulMusic13SetWidenValueEf
                    ((Stereo3DSurround *)this->colorful,in_s0);
                }
                goto LAB_00071250;
            }
            if (0x10012 < param_1) {
                if (param_1 == 0x10014) {
                    if (this->colorful != nullptr) {
                        ColorfulMusic::SetDepthValue(this->colorful,(short)param_2);
                    }
                }
                else {
                    if (param_1 < 0x10015) {
                        if (this->colorful != nullptr) {
                            Stereo3DSurround::~ZN13ColorfulMusic16SetMidImageValueEf
                            ((Stereo3DSurround *)this->colorful,in_s0);
                        }
                    }
                    else {
                        if (this->diffSurround != nullptr) {
                            DiffSurround::SetEnable(this->diffSurround,bVar1);
                        }
                    }
                }
                goto LAB_00071250;
            }
            if (param_1 != 0x10010) {
                if ((param_1 == 0x10011) && (this->colorful != nullptr)) {
                    ColorfulMusic::SetEnable(this->colorful,bVar1);
                }
                goto LAB_00071250;
            }
            LAB_000716d4:
            if (this->iirFilter != nullptr) {
                IIRFilter::SetBandLevel((int)this->iirFilter,in_s0);
            }
            goto LAB_00071250;
        }
        if (param_1 == 0x10001) {
            if (((uint)param_2 < 3) && (this->field_0x7c != param_2)) {
                this->field_0x7c = param_2;
                ResetAllEffects(this);
            }
            goto LAB_00071250;
        }
        if (0x10001 < param_1) {
            if (param_1 == 0x10004) {
                LAB_00071de0:
                if (this->convolver != nullptr) {
                    Convolver::PrepareKernelBuffer(this->convolver,param_2,param_3,param_4);
                }
                goto LAB_00071250;
            }
            if (param_1 < 0x10005) {
                if (param_1 == 0x10002) goto LAB_000717e4;
                if (param_1 != 0x10003) goto LAB_00071250;
                goto LAB_00071720;
            }
            if (param_1 == 0x10006) {
                LAB_00071384:
                if (this->convolver != nullptr) {
                    Convolver::CommitKernelBuffer(this->convolver,param_2,param_3,param_4);
                }
                goto LAB_00071250;
            }
            if (param_1 < 0x10007) goto LAB_00071e00;
            goto LAB_000715b8;
        }
        if (param_1 == 0x9003) {
            __android_log_print(4,"ViPER4Android_v2","Reset required");
            ResetAllEffects(this);
            goto LAB_00071250;
        }
        if (param_1 < 0x9004) {
            if (param_1 == 0x9001) {
                __android_log_print(4,"ViPER4Android_v2","Driver general communication");
                __android_log_print(4,"ViPER4Android_v2","Driver and server are alive");
            }
            else {
                if (param_1 == 0x9002) {
                    *(bool *)&this->field_0x6c = bVar1;
                }
            }
            goto LAB_00071250;
        }
        if (param_1 == 0x9005) {
            *(bool *)&this->field_0x7a = bVar1;
            goto LAB_00071250;
        }
        if (param_1 < 0x9005) {
            if ((*(char *)&this->field_0x79 == '\0') && (iVar7 != 0)) {
                ResetAllEffects(this);
            }
            *(bool *)&this->field_0x79 = bVar1;
            goto LAB_00071250;
        }
        if (param_1 != 0x9006) goto LAB_00071250;
        __android_log_print(4,"ViPER4Android_v2","Begin self diagnose procedure ...");
        uVar25 = 5;
        uVar26 = 0;
        uVar27 = 4;
        __android_log_print(4,"ViPER4Android_v2","[DN] Driver version %d.%d.%d.%d",2,5,0,4);
        __android_log_print(4,"ViPER4Android_v2","[DN] Driver is fixed pointing mode");
        uVar5 = this->samplerate;
        if (0xf3c < uVar5 - 0xac44) {
            __android_log_print(4,"ViPER4Android_v2",
                                "[DN] *Current sampling rate is %d ... Bad, unsupported sampling rate",
                                uVar5,uVar25,uVar26,uVar27);
            __android_log_print(4,"ViPER4Android_v2","Self diagnose procedure finished");
            goto LAB_00071250;
        }
        __android_log_print(4,"ViPER4Android_v2","[DN] Current sampling rate is %d ... OK",uVar5,uVar25,
                            uVar26,uVar27);
        if (*(char *)&this->field_0x5 == '\0') {
            __android_log_print(4,"ViPER4Android_v2",
                                "[DN] *Problem found, system has required an unsupported audio format",0,
                                uVar25,uVar26,uVar27);
            __android_log_print(4,"ViPER4Android_v2",
                                "[DN] *Please check system log for further information");
            __android_log_print(4,"ViPER4Android_v2","Self diagnose procedure finished");
            goto LAB_00071250;
        }
        if (*(char *)&this->field_0x4 == '\0') {
            __android_log_print(4,"ViPER4Android_v2","[DN] Audio effect engine enabled = false",0,uVar25,
                                uVar26,uVar27);
        }
        else {
            __android_log_print(4,"ViPER4Android_v2","[DN] Audio effect engine enabled = true",
                                *(char *)&this->field_0x4,uVar25,uVar26,uVar27);
        }
        if (*(char *)&this->field_0x7a == '\0') {
            __android_log_print(4,"ViPER4Android_v2","[DN] Audio effect engine force enabled = false");
        }
        else {
            __android_log_print(4,"ViPER4Android_v2","[DN] Audio effect engine force enabled = true");
        }
        if (*(char *)&this->field_0x79 == '\0') {
            __android_log_print(4,"ViPER4Android_v2","[DN] Internal switch enabled = false");
        }
        else {
            __android_log_print(4,"ViPER4Android_v2","[DN] Internal switch enabled = true");
        }
        if (1 < this->field_0x7c - 1) {
            __android_log_print(4,"ViPER4Android_v2","[DN] *Wrong effect type found = %d");
            __android_log_print(4,"ViPER4Android_v2","[DN] *Fixing effect type ... OK");
            __android_log_print(4,"ViPER4Android_v2","[DN] *Resetting instance ... OK");
            this->field_0x7c = 1;
            ResetAllEffects(this);
        }
        __android_log_print(4,"ViPER4Android_v2","[DN] Memory and sub effects checking ...");
        if (this == (ProcessUnit_FX *)this->field_0x68) {
            __android_log_print(4,"ViPER4Android_v2","[DN] Instance pointer is %x ... OK",this);
        }
        else {
            __android_log_print(4,"ViPER4Android_v2",
                                "[DN] *Wrong instance pointer found, this may caused by a bug of system");
            __android_log_print(4,"ViPER4Android_v2","[DN] *Fixing instance pointer ... OK");
            __android_log_print(4,"ViPER4Android_v2","[DN] *Resetting instance ... OK");
            this->field_0x68 = (undefined *)this;
            ResetAllEffects(this);
        }
        if (*(char *)&this->field_0x78 == '\0') {
            __android_log_print(4,"ViPER4Android_v2",
                                "[DN] *Memory pool corrupted, this may caused by lacking of memory");
            __android_log_print(4,"ViPER4Android_v2",
                                "[DN] *Rebuilding memory pool and re-initialize all sub effects");
            pAVar8 = this->floatIntBuffer;
            if (pAVar8 != nullptr) {
                AdaptiveBuffer_FPI32::~AdaptiveBuffer_FPI32(pAVar8);
                operator_delete(pAVar8);
            }
            pWVar9 = this->waveBuffer;
            this->floatIntBuffer = nullptr;
            if (pWVar9 != nullptr) {
                WaveBuffer_R32::~WaveBuffer_R32(pWVar9);
                operator_delete(pWVar9);
            }
            pCVar10 = this->convolver;
            this->waveBuffer = nullptr;
            if (pCVar10 != nullptr) {
                Convolver::~Convolver(pCVar10);
                operator_delete(pCVar10);
            }
            pVVar11 = this->vhe;
            this->convolver = nullptr;
            if (pVVar11 != nullptr) {
                VHE::~VHE(pVVar11);
                operator_delete(pVVar11);
            }
            pVVar12 = this->vddc;
            this->vhe = nullptr;
            if (pVVar12 != nullptr) {
                ViPERDDC::~ViPERDDC(pVVar12);
                operator_delete(pVVar12);
            }
            pSVar13 = this->spectrumExtend;
            this->vddc = nullptr;
            if (pSVar13 != nullptr) {
                SpectrumExtend::~SpectrumExtend(pSVar13);
                operator_delete(pSVar13);
            }
            pIVar14 = this->iirFilter;
            this->spectrumExtend = nullptr;
            if (pIVar14 != nullptr) {
                IIRFilter::~IIRFilter(pIVar14);
                operator_delete(pIVar14);
            }
            pCVar15 = this->colorful;
            this->iirFilter = nullptr;
            if (pCVar15 != nullptr) {
                TimeConstDelay::~TimeConstDelay((TimeConstDelay *)&pCVar15->field_0x34);
                TimeConstDelay::~TimeConstDelay((TimeConstDelay *)&pCVar15->field_0x28);
                operator_delete(pCVar15);
            }
            pRVar16 = this->reverb;
            this->colorful = nullptr;
            if (pRVar16 != nullptr) {
                CRevModel::~CRevModel(&pRVar16->field_0x14);
                operator_delete(pRVar16);
            }
            this->reverb = nullptr;
            if (this->playbackGain != nullptr) {
                operator_delete(this->playbackGain);
            }
            pFVar17 = this->fetCompressor;
            this->playbackGain = nullptr;
            if (pFVar17 != nullptr) {
                FETCompressor::~FETCompressor(pFVar17);
                operator_delete(pFVar17);
            }
            this->fetCompressor = nullptr;
            if (this->dynamicSystem != nullptr) {
                operator_delete(this->dynamicSystem);
            }
            pVVar18 = this->vbass;
            this->dynamicSystem = nullptr;
            if (pVVar18 != nullptr) {
                ViPERBass::~ViPERBass(pVVar18);
                operator_delete(pVVar18);
            }
            pVVar19 = this->vclarity;
            this->vbass = nullptr;
            if (pVVar19 != nullptr) {
                ViPERClarity::~ViPERClarity(pVVar19);
                operator_delete(pVVar19);
            }
            pDVar20 = this->diffSurround;
            this->vclarity = nullptr;
            if (pDVar20 != nullptr) {
                DiffSurround::~DiffSurround(pDVar20);
                operator_delete(pDVar20);
            }
            pCVar21 = this->cure;
            this->diffSurround = nullptr;
            if (pCVar21 != nullptr) {
                Cure::~Cure(pCVar21);
                operator_delete(pCVar21);
            }
            this->cure = nullptr;
            if (this->tubeSim != nullptr) {
                operator_delete(this->tubeSim);
            }
            pAVar23 = this->analogx;
            this->tubeSim = nullptr;
            if (pAVar23 != nullptr) {
                pHVar22 = (Harmonic *)&pAVar23->field_0xc0;
                do {
                    pHVar22 = pHVar22 + -1;
                    Harmonic::~Harmonic(pHVar22);
                } while (&pAVar23->field_0x48 != pHVar22);
                operator_delete(pAVar23);
            }
            this->analogx = nullptr;
            if (this->speakerCorrection != nullptr) {
                operator_delete(this->speakerCorrection);
            }
            this->speakerCorrection = nullptr;
            if (this->softLimit1 != nullptr) {
                operator_delete(this->softLimit1);
            }
            this->softLimit1 = nullptr;
            if (this->softLimit2 != nullptr) {
                operator_delete(this->softLimit2);
            }
            this->softLimit2 = nullptr;
            pAVar8 = (AdaptiveBuffer_FPI32 *)operator_new(0x20);
            AdaptiveBuffer_FPI32::AdaptiveBuffer_FPI32(pAVar8,2,0x1000);
            this->floatIntBuffer = pAVar8;
            pWVar9 = (WaveBuffer_R32 *)operator_new(0x20);
            WaveBuffer_R32::WaveBuffer_R32(pWVar9,2,0x1000);
            this->waveBuffer = pWVar9;
            pCVar10 = (Convolver *)operator_new(0x174);
            Convolver::Convolver(pCVar10);
            this->convolver = pCVar10;
            pVVar11 = (VHE *)operator_new(0x38);
            VHE::VHE(pVVar11);
            this->vhe = pVVar11;
            pVVar12 = (ViPERDDC *)operator_new(0x34);
            ViPERDDC::ViPERDDC(pVVar12);
            this->vddc = pVVar12;
            pSVar13 = (SpectrumExtend *)operator_new(0x118);
            SpectrumExtend::SpectrumExtend(pSVar13);
            this->spectrumExtend = pSVar13;
            pIVar14 = (IIRFilter *)operator_new(0x860);
            IIRFilter::IIRFilter(pIVar14,10);
            this->iirFilter = pIVar14;
            pCVar15 = (ColorfulMusic *)operator_new(0x6c);
            ColorfulMusic::ColorfulMusic(pCVar15);
            this->colorful = pCVar15;
            pRVar16 = (Reverberation *)operator_new(0x2ec);
            Reverberation::Reverberation(pRVar16);
            this->reverb = pRVar16;
            this_00 = (PlaybackGain *)operator_new(0x78);
            PlaybackGain::PlaybackGain(this_00);
            this->playbackGain = this_00;
            pFVar17 = (FETCompressor *)operator_new(0xb0);
            FETCompressor::FETCompressor(pFVar17);
            this->fetCompressor = pFVar17;
            this_01 = (DynamicSystem *)operator_new(0x138);
            DynamicSystem::DynamicSystem(this_01);
            this->dynamicSystem = this_01;
            pVVar18 = (ViPERBass *)operator_new(0x2c);
            ViPERBass::ViPERBass(pVVar18);
            this->vbass = pVVar18;
            pVVar19 = (ViPERClarity *)operator_new(0xe0);
            ViPERClarity::ViPERClarity(pVVar19);
            this->vclarity = pVVar19;
            pDVar20 = (DiffSurround *)operator_new(0x14);
            DiffSurround::DiffSurround(pDVar20);
            this->diffSurround = pDVar20;
            pCVar21 = (Cure *)operator_new(0x50);
            Cure::Cure(pCVar21);
            this->cure = pCVar21;
            pTVar3 = (TubeSimulator *)operator_new(0xc);
            TubeSimulator::TubeSimulator(pTVar3);
            this->tubeSim = pTVar3;
            pAVar23 = (AnalogX *)operator_new(0x164);
            AnalogX::AnalogX(pAVar23);
            this->analogx = pAVar23;
            this_02 = (SpeakerCorrection *)operator_new(0xe0);
            SpeakerCorrection::SpeakerCorrection(this_02);
            this->speakerCorrection = this_02;
            pSVar4 = (SoftwareLimiter *)operator_new(0xc28);
            SoftwareLimiter::SoftwareLimiter(pSVar4);
            this->softLimit1 = pSVar4;
            pSVar4 = (SoftwareLimiter *)operator_new(0xc28);
            SoftwareLimiter::SoftwareLimiter(pSVar4);
            pAVar8 = this->floatIntBuffer;
            this->softLimit2 = pSVar4;
            if (pAVar8 != nullptr) {
                if (((((((this->waveBuffer != nullptr) && (this->softLimit1 != nullptr)) && (pSVar4 != nullptr)) &&
                       ((this->convolver != nullptr && (this->vhe != nullptr)))) &&
                      (((this->vddc != nullptr && ((this->spectrumExtend != nullptr && (this->iirFilter != nullptr))))
                        && (this->colorful != nullptr)))) &&
                     ((((this->reverb != nullptr && (this->playbackGain != nullptr)) &&
                        (this->fetCompressor != nullptr)) &&
                       (((this->vbass != nullptr && (this->vclarity != nullptr)) &&
                         ((this->diffSurround != nullptr &&
                           ((this->dynamicSystem != nullptr && (this->cure != nullptr)))))))))) &&
                    ((this->tubeSim != nullptr && ((this->analogx != nullptr && (this->speakerCorrection != nullptr)))
                    ))) {
                    *(undefined *)&this->field_0x78 = 1;
                    ResetAllEffects(this);
                    __android_log_print(4,"ViPER4Android_v2",
                                        "[DN] *Memory pool is OK and all sub effects re-initialized");
                    goto LAB_000710f8;
                }
                AdaptiveBuffer_FPI32::~AdaptiveBuffer_FPI32(pAVar8);
                operator_delete(pAVar8);
            }
            pWVar9 = this->waveBuffer;
            this->floatIntBuffer = nullptr;
            if (pWVar9 != nullptr) {
                WaveBuffer_R32::~WaveBuffer_R32(pWVar9);
                operator_delete(pWVar9);
            }
            pCVar10 = this->convolver;
            this->waveBuffer = nullptr;
            if (pCVar10 != nullptr) {
                Convolver::~Convolver(pCVar10);
                operator_delete(pCVar10);
            }
            pVVar11 = this->vhe;
            this->convolver = nullptr;
            if (pVVar11 != nullptr) {
                VHE::~VHE(pVVar11);
                operator_delete(pVVar11);
            }
            pVVar12 = this->vddc;
            this->vhe = nullptr;
            if (pVVar12 != nullptr) {
                ViPERDDC::~ViPERDDC(pVVar12);
                operator_delete(pVVar12);
            }
            pSVar13 = this->spectrumExtend;
            this->vddc = nullptr;
            if (pSVar13 != nullptr) {
                SpectrumExtend::~SpectrumExtend(pSVar13);
                operator_delete(pSVar13);
            }
            pIVar14 = this->iirFilter;
            this->spectrumExtend = nullptr;
            if (pIVar14 != nullptr) {
                IIRFilter::~IIRFilter(pIVar14);
                operator_delete(pIVar14);
            }
            pCVar15 = this->colorful;
            this->iirFilter = nullptr;
            if (pCVar15 != nullptr) {
                TimeConstDelay::~TimeConstDelay((TimeConstDelay *)&pCVar15->field_0x34);
                TimeConstDelay::~TimeConstDelay((TimeConstDelay *)&pCVar15->field_0x28);
                operator_delete(pCVar15);
            }
            pRVar16 = this->reverb;
            this->colorful = nullptr;
            if (pRVar16 != nullptr) {
                CRevModel::~CRevModel(&pRVar16->field_0x14);
                operator_delete(pRVar16);
            }
            this->reverb = nullptr;
            if (this->playbackGain != nullptr) {
                operator_delete(this->playbackGain);
            }
            pFVar17 = this->fetCompressor;
            this->playbackGain = nullptr;
            if (pFVar17 != nullptr) {
                FETCompressor::~FETCompressor(pFVar17);
                operator_delete(pFVar17);
            }
            this->fetCompressor = nullptr;
            if (this->dynamicSystem != nullptr) {
                operator_delete(this->dynamicSystem);
            }
            pVVar18 = this->vbass;
            this->dynamicSystem = nullptr;
            if (pVVar18 != nullptr) {
                ViPERBass::~ViPERBass(pVVar18);
                operator_delete(pVVar18);
            }
            pVVar19 = this->vclarity;
            this->vbass = nullptr;
            if (pVVar19 != nullptr) {
                ViPERClarity::~ViPERClarity(pVVar19);
                operator_delete(pVVar19);
            }
            pDVar20 = this->diffSurround;
            this->vclarity = nullptr;
            if (pDVar20 != nullptr) {
                DiffSurround::~DiffSurround(pDVar20);
                operator_delete(pDVar20);
            }
            pCVar21 = this->cure;
            this->diffSurround = nullptr;
            if (pCVar21 != nullptr) {
                Cure::~Cure(pCVar21);
                operator_delete(pCVar21);
            }
            this->cure = nullptr;
            if (this->tubeSim != nullptr) {
                operator_delete(this->tubeSim);
            }
            pAVar23 = this->analogx;
            this->tubeSim = nullptr;
            if (pAVar23 != nullptr) {
                pHVar22 = (Harmonic *)&pAVar23->field_0xc0;
                do {
                    pHVar22 = pHVar22 + -1;
                    Harmonic::~Harmonic(pHVar22);
                } while (&pAVar23->field_0x48 != pHVar22);
                operator_delete(pAVar23);
            }
            this->analogx = nullptr;
            if (this->speakerCorrection != nullptr) {
                operator_delete(this->speakerCorrection);
            }
            this->speakerCorrection = nullptr;
            if (this->softLimit1 != nullptr) {
                operator_delete(this->softLimit1);
            }
            this->softLimit1 = nullptr;
            if (this->softLimit2 != nullptr) {
                operator_delete(this->softLimit2);
            }
            this->softLimit2 = nullptr;
            *(undefined *)&this->field_0x78 = 0;
            __android_log_print(4,"ViPER4Android_v2",
                                "[DN] *Can not rebuild memory pool, audio system was broken");
            __android_log_print(4,"ViPER4Android_v2","Self diagnose procedure finished");
        }
        else {
            __android_log_print(4,"ViPER4Android_v2","[DN] Memory pool and all sub effects are OK");
            LAB_000710f8:
            __android_log_print(4,"ViPER4Android_v2","[DN] Resetting instance ...");
            ResetAllEffects(this);
            __android_log_print(4,"ViPER4Android_v2","Self diagnose procedure finished");
        }
        goto LAB_00071250;
    }
    if (param_1 == 0x1004f) {
        LAB_00071e2c:
        if (this->fetCompressor != nullptr) {
            FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
        }
        goto LAB_00071250;
    }
    if (param_1 < 0x10050) {
        if (param_1 != 0x10041) {
            if (param_1 < 0x10042) {
                if (param_1 == 0x1003a) {
                    LAB_000715b8:
                    if (this->convolver != nullptr) {
                        Convolver::SetCrossChannel(this->convolver,in_s0);
                    }
                    goto LAB_00071250;
                }
                if (0x1003a < param_1) {
                    if (param_1 == 0x1003d) {
                        LAB_00071900:
                        if (this->reverb != nullptr) {
                            Reverberation::SetEnable(this->reverb,bVar1);
                        }
                        goto LAB_00071250;
                    }
                    if (0x1003d < param_1) {
                        if (param_1 != 0x1003f) {
                            if (0x1003f < param_1) {
                                LAB_000707e4:
                                if (this->reverb != nullptr) {
                                    Reverberation::SetDamp(this->reverb,(int)((float)(longlong)param_2 / 100.0));
                                }
                                goto LAB_00071250;
                            }
                            LAB_00071840:
                            if (this->reverb != nullptr) {
                                Reverberation::SetRoomSize(this->reverb,(int)((float)(longlong)param_2 / 100.0));
                            }
                            goto LAB_00071250;
                        }
                        goto LAB_00071918;
                    }
                    if (param_1 == 0x1003b) goto LAB_00071d64;
                    if (param_1 != 0x1003c) goto LAB_00071250;
                    goto LAB_000716d4;
                }
                if (param_1 == 0x10036) {
                    LAB_00071720:
                    if (0 < param_6) {
                        memset(acStack292,0,0x100);
                        memcpy(acStack292,param_7,param_6);
                        if (this->convolver != nullptr) {
                            Convolver::SetKernel(this->convolver,acStack292);
                        }
                    }
                    goto LAB_00071250;
                }
                if (0x10036 < param_1) {
                    if (param_1 == 0x10038) {
                        LAB_00071e00:
                        psVar2 = param_7;
                        if (param_7 != nullptr) {
                            psVar2 = (signed *)param_6;
                        }
                        if (((param_7 != nullptr && param_6 != 0) && -1 < (int)psVar2) && (this->convolver != nullptr)
                                ) {
                            Convolver::SetKernelBuffer(this->convolver,param_2,(float *)param_7,param_6);
                        }
                        goto LAB_00071250;
                    }
                    if (0x10038 < param_1) goto LAB_00071384;
                    goto LAB_00071de0;
                }
                if ((Elf32_Phdr *)param_1 != Elf32_Phdr_ARRAY_00010034) {
                    if (param_1 != 0x10035) goto LAB_00071250;
                    LAB_000717e4:
                    if (this->convolver != nullptr) {
                        Convolver::SetEnable(this->convolver,bVar1);
                    }
                    goto LAB_00071250;
                }
            }
            else {
                if (param_1 == 0x10048) goto LAB_00071ac4;
                if (param_1 < 0x10049) {
                    if (param_1 != 0x10044) {
                        if (param_1 < 0x10045) {
                            if (param_1 != 0x10042) {
                                if ((param_1 == 0x10043) && (this->speakerCorrection != nullptr)) {
                                    SpeakerCorrection::SetEnable(this->speakerCorrection,bVar1);
                                }
                                goto LAB_00071250;
                            }
                            LAB_00071608:
                            if (this->reverb != nullptr) {
                                Reverberation::SetDry(this->reverb,(int)((float)(longlong)param_2 / 100.0));
                            }
                            goto LAB_00071250;
                        }
                        if (param_1 != 0x10046) {
                            if (param_1 < 0x10047) goto LAB_00071b1c;
                            goto LAB_00071644;
                        }
                        goto LAB_00071564;
                    }
                    goto LAB_00071f48;
                }
                if (param_1 == 0x1004b) {
                    LAB_0007085c:
                    if (this->fetCompressor != nullptr) {
                        FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
                    }
                    goto LAB_00071250;
                }
                if (0x1004b < param_1) {
                    if (param_1 == 0x1004d) goto LAB_000719f8;
                    if (0x1004d < param_1) goto LAB_000713cc;
                    goto LAB_00071f78;
                }
                if (param_1 != 0x10049) {
                    if (param_1 != 0x1004a) goto LAB_00071250;
                    goto LAB_00071788;
                }
            }
            if (this->softLimit1 != nullptr) {
                in_s0 = (float)SoftwareLimiter::SetGate(this->softLimit1,in_s0);
            }
            if (this->softLimit2 != nullptr) {
                SoftwareLimiter::SetGate(this->softLimit2,in_s0);
            }
            goto LAB_00071250;
        }
        LAB_00071b78:
        if (this->reverb != nullptr) {
            Reverberation::SetWet(this->reverb,(int)((float)(longlong)param_2 / 100.0));
        }
        goto LAB_00071250;
    }
    if (param_1 == 0x1005d) {
        LAB_00071f78:
        if (this->fetCompressor != nullptr) {
            FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
        }
        goto LAB_00071250;
    }
    if (param_1 < 0x1005e) {
        if (param_1 == 0x10056) {
            LAB_000711c8:
            if (this->fetCompressor != nullptr) {
                FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
            }
            goto LAB_00071250;
        }
        if (0x10056 < param_1) {
            if (param_1 == 0x10059) {
                LAB_00071940:
                if (this->fetCompressor != nullptr) {
                    FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
                }
                goto LAB_00071250;
            }
            if (0x10059 < param_1) {
                if (param_1 == 0x1005b) {
                    LAB_00071788:
                    pFVar17 = this->fetCompressor;
                    if (pFVar17 != nullptr) {
                        if (iVar7 == 0) {
                            FETCompressor::SetParameter((int)pFVar17,in_s0);
                            this->field_0x88 = 0;
                        }
                        else {
                            if (this->field_0x88 == 0) {
                                FETCompressor::SetParameter((int)pFVar17,in_s0);
                                FETCompressor::Reset(this->fetCompressor);
                                this->field_0x88 = 1;
                            }
                            else {
                                FETCompressor::SetParameter((int)pFVar17,in_s0);
                                this->field_0x88 = 1;
                            }
                        }
                    }
                    goto LAB_00071250;
                }
                if (0x1005b < param_1) goto LAB_0007085c;
                LAB_00071690:
                if (this->fetCompressor != nullptr) {
                    FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
                }
                goto LAB_00071250;
            }
            if (param_1 != 0x10057) {
                if (param_1 != 0x10058) goto LAB_00071250;
                LAB_000718d4:
                if (this->fetCompressor != nullptr) {
                    FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
                }
                goto LAB_00071250;
            }
            LAB_00071c98:
            if (this->fetCompressor != nullptr) {
                FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
            }
            goto LAB_00071250;
        }
        if (param_1 == 0x10052) goto LAB_00071418;
        if (param_1 < 0x10053) {
            if (param_1 == 0x10050) {
                LAB_00071aa0:
                if (this->fetCompressor != nullptr) {
                    FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
                }
                goto LAB_00071250;
            }
            if (param_1 != 0x10051) goto LAB_00071250;
            LAB_00071888:
            if (this->fetCompressor != nullptr) {
                FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
            }
            goto LAB_00071250;
        }
        if (param_1 == 0x10054) {
            LAB_00071c74:
            if (this->fetCompressor != nullptr) {
                FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
            }
            goto LAB_00071250;
        }
        if (0x10054 < param_1) goto LAB_00071330;
    }
    else {
        if (param_1 != 0x10064) {
            if (param_1 < 0x10065) {
                if (param_1 == 0x10060) goto LAB_00071e2c;
                if (param_1 < 0x10061) {
                    if (param_1 != 0x1005e) {
                        if (param_1 != 0x1005f) goto LAB_00071250;
                        LAB_000713cc:
                        if (this->fetCompressor != nullptr) {
                            FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
                        }
                        goto LAB_00071250;
                    }
                    LAB_000719f8:
                    if (this->fetCompressor != nullptr) {
                        FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
                    }
                    goto LAB_00071250;
                }
                if (param_1 == 0x10062) goto LAB_00071888;
                if (param_1 < 0x10063) goto LAB_00071aa0;
                LAB_00071418:
                if (this->fetCompressor != nullptr) {
                    FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
                }
                goto LAB_00071250;
            }
            if (param_1 == 0x10068) goto LAB_00071c98;
            if (0x10068 < param_1) {
                if (param_1 != 0x1006a) {
                    if (param_1 < 0x1006a) goto LAB_000718d4;
                    if (param_1 != 0x1006b) goto LAB_00071250;
                    goto LAB_00071690;
                }
                goto LAB_00071940;
            }
            if (param_1 == 0x10066) {
                LAB_00071330:
                if (this->fetCompressor != nullptr) {
                    FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
                }
                goto LAB_00071250;
            }
            if (param_1 < 0x10067) goto LAB_00071c74;
            goto LAB_000711c8;
        }
    }
    if (this->fetCompressor != nullptr) {
        FETCompressor::SetParameter((int)this->fetCompressor,in_s0);
    }
    LAB_00071250:
    if (local_24 != __stack_chk_guard) {
        // WARNING: Subroutine does not return
        __stack_chk_fail();
    }
    return;
}



// ProcessUnit_FX::processBuffer(short*, int)

int ProcessUnit_FX::processBuffer(short *param_1,int param_2) {
    char cVar1;
    AdaptiveBuffer_FPI32 *this_00;
    int *piVar2;
    float *pfVar3;
    uint uVar4;
    int iVar5;
    int *piVar6;
    WaveBuffer_R32 *this_01;
    uint uVar7;
    int iVar8;
    timeval local_30;

    cVar1 = *(char *)&this->field_0x4;
    if (*(char *)&this->field_0x7a == '\0') {
        joined_r0x000725b0:
        if (cVar1 == '\0') {
            return -0x3d;
        }
    }
    else {
        if (cVar1 == '\0') {
            cVar1 = *(char *)&this->field_0x79;
            goto joined_r0x000725b0;
        }
    }
    iVar5 = this->field_0x7c;
    if (iVar5 == 0) {
        return 0;
    }
    if (param_2 < 1) {
        return 0;
    }
    if (*(char *)&this->field_0x78 == '\0') {
        return 0;
    }
    if (*(char *)&this->field_0x6c != '\0') {
        local_30.tv_sec = 0;
        local_30.tv_usec = 0;
        gettimeofday(&local_30,nullptr);
        iVar5 = this->field_0x7c;
        iVar8 = local_30.tv_sec * 1000 + local_30.tv_usec / 1000;
        *(int *)&this->field_0x70 = iVar8;
        *(int *)((int)&this->field_0x70 + 4) = iVar8 >> 0x1f;
    }
    if (iVar5 == 2) {
        iVar5 = Convolver::GetEnabled(this->convolver);
        if (iVar5 == 0) {
            iVar5 = this->field_0x7c;
            goto LAB_000724c0;
        }
        LAB_00072618:
        iVar8 = this->field_0x7c + -2;
        if (iVar8 != 0) {
            iVar8 = 1;
        }
        LAB_00072624:
        iVar5 = WaveBuffer_R32::PushSamples(this->waveBuffer,param_1,param_2);
        if (iVar5 == 0) {
            WaveBuffer_R32::Reset(this->waveBuffer);
            return 0;
        }
        pfVar3 = (float *)WaveBuffer_R32::GetCurrentBufferR32Ptr(this->waveBuffer);
        uVar4 = Convolver::Process(this->convolver,pfVar3,pfVar3,param_2);
        if (iVar8 != 0) {
            uVar4 = VHE::Process(this->vhe,pfVar3,pfVar3,uVar4);
        }
        WaveBuffer_R32::SetBufferOffset(this->waveBuffer,uVar4);
        iVar5 = AdaptiveBuffer_FPI32::PushZero(this->floatIntBuffer,uVar4);
        if (iVar5 == 0) {
            WaveBuffer_R32::Reset(this->waveBuffer);
            AdaptiveBuffer_FPI32::FlushBuffer(this->floatIntBuffer);
            return 0;
        }
        this_01 = this->waveBuffer;
        piVar2 = (int *)AdaptiveBuffer_FPI32::GetBufferPointer(this->floatIntBuffer);
        uVar4 = WaveBuffer_R32::PopSamples(this_01,piVar2,uVar4,true);
        AdaptiveBuffer_FPI32::SetBufferOffset(this->floatIntBuffer,uVar4);
        piVar2 = (int *)AdaptiveBuffer_FPI32::GetBufferPointer(this->floatIntBuffer);
        if (uVar4 == 0) goto LAB_000726cc;
    }
    else {
        LAB_000724c0:
        if (iVar5 == 1) {
            iVar5 = Convolver::GetEnabled(this->convolver);
            if (iVar5 != 0) goto LAB_00072618;
            iVar5 = VHE::GetEnabled(this->vhe);
            iVar8 = this->field_0x7c + -2;
            if (iVar8 != 0) {
                iVar8 = 1;
            }
            if (iVar5 == 0) goto LAB_000724c8;
            goto LAB_00072624;
        }
        LAB_000724c8:
        iVar5 = AdaptiveBuffer_FPI32::PushFrames(this->floatIntBuffer,param_1,param_2);
        this_00 = this->floatIntBuffer;
        if (iVar5 == 0) goto LAB_0007270c;
        AdaptiveBuffer_FPI32::SetBufferOffset(this_00,param_2);
        piVar2 = (int *)AdaptiveBuffer_FPI32::GetBufferPointer(this->floatIntBuffer);
        uVar4 = param_2;
    }
    if (this->field_0x7c == 1) {
        ViPERDDC::Process(this->vddc,piVar2,param_2);
        SpectrumExtend::Process(this->spectrumExtend,piVar2,param_2);
        IIRFilter::Process(this->iirFilter,piVar2,uVar4);
        ColorfulMusic::Process(this->colorful,piVar2,uVar4);
        DiffSurround::Process(this->diffSurround,piVar2,uVar4);
        Reverberation::Process(this->reverb,piVar2,uVar4);
        PlaybackGain::Process(this->playbackGain,piVar2,uVar4);
        if (this->field_0x88 != 0) {
            FETCompressor::Process(this->fetCompressor,piVar2,uVar4);
        }
        DynamicSystem::Process(this->dynamicSystem,piVar2,uVar4);
        ViPERBass::Process(this->vbass,piVar2,uVar4);
        ViPERClarity::Process(this->vclarity,piVar2,uVar4);
        Cure::Process(this->cure,piVar2,uVar4);
        TubeSimulator::TubeProcess(this->tubeSim,piVar2,param_2);
        AnalogX::Process(this->analogx,piVar2,uVar4);
    }
    else {
        if (this->field_0x7c == 2) {
            IIRFilter::Process(this->iirFilter,piVar2,uVar4);
            Reverberation::Process(this->reverb,piVar2,uVar4);
            SpeakerCorrection::Process(this->speakerCorrection,piVar2,uVar4);
            PlaybackGain::Process(this->playbackGain,piVar2,uVar4);
            if (this->field_0x88 != 0) {
                FETCompressor::Process(this->fetCompressor,piVar2,uVar4);
            }
        }
    }
    if (this->field_0xd8 != 0x2000000) {
        AdaptiveBuffer_FPI32::ScaleFrames(this->floatIntBuffer,this->field_0xd8);
    }
    if ((((int)this->field_0xdc < 0x2000000) || ((int)this->field_0xe0 < 0x2000000)) &&
        (this->field_0x7c == 1)) {
        AdaptiveBuffer_FPI32::PanFrames(this->floatIntBuffer,this->field_0xdc,this->field_0xe0);
    }
    if (uVar4 << 1 != 0) {
        uVar7 = 0;
        piVar6 = piVar2 + 1;
        do {
            uVar7 = uVar7 + 2;
            iVar5 = SoftwareLimiter::Process((int)this->softLimit1);
            piVar6[-1] = iVar5;
            iVar5 = SoftwareLimiter::Process((int)this->softLimit2);
            piVar2[1] = iVar5;
            piVar2 = piVar2 + 2;
            piVar6 = piVar6 + 2;
        } while (uVar7 < uVar4 << 1);
    }
    iVar5 = AdaptiveBuffer_FPI32::PopFrames(this->floatIntBuffer,param_1,uVar4);
    if (iVar5 == 0) {
        this_00 = this->floatIntBuffer;
        LAB_0007270c:
        AdaptiveBuffer_FPI32::FlushBuffer(this_00);
        return iVar5;
    }
    if ((uint)param_2 <= uVar4) {
        return 0;
    }
    LAB_000726cc:
    memmove(param_1 + (param_2 - uVar4) * 2,param_1,uVar4 << 2);
    memset(param_1,0,(param_2 - uVar4) * 4);
    return 0;
}



// ProcessUnit_FX::command(unsigned int, unsigned int, void*, unsigned int*, void*)

int ProcessUnit_FX::command(uint param_1,uint param_2,void *param_3,uint *param_4,void *param_5) {
    byte bVar1;
    int EVar2;
    Convolver *this_00;
    undefined4 uVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    uint uVar7;
    timeval local_28;

    if (param_1 == 3) {
        if (*(char *)&this->field_0x4 != '\0') goto switchD_00072a04_caseD_a;
        LAB_00072978:
        ResetAllEffects(this);
        switchD_00072a04_caseD_a:
        EVar2 = Effect::command((Effect *)this,param_1,param_2,param_3,param_4,param_5);
        return EVar2;
    }
    if ((param_1 & 0xfffffffd) == 0) goto LAB_00072978;
    if (param_1 == 1) {
        if ((((param_3 != nullptr) && (param_2 == 0x40)) && (param_5 != nullptr)) && (*param_4 == 4)) {
            uVar7 = this->samplerate;
            EVar2 = Effect::configure((Effect *)this,(effect_config_t *)param_3);
            if (EVar2 == OK) {
                if (this->samplerate != uVar7) {
                    ResetAllEffects(this);
                }
                *(undefined4 *)param_5 = 0;
                return OK;
            }
            *(int *)param_5 = EVar2;
            return OK;
        }
        return EINVAL;
    }
    if (param_1 == 5) {
        if (*(int *)((int)param_3 + 4) != 4) {
            LAB_00072a40:
            *(undefined4 *)param_5 = 0xffffffea;
            return OK;
        }
        iVar5 = *(int *)((int)param_3 + 8);
        iVar4 = *(int *)((int)param_3 + 0xc);
        if (iVar5 == 4) {
            iVar5 = *(int *)((int)param_3 + 0x10);
            iVar6 = 0;
        }
        else {
            if (iVar5 != 8) {
                if (iVar5 == 0xc) {
                    DispatchCommand(this,iVar4,*(int *)((int)param_3 + 0x10),*(int *)((int)param_3 + 0x14),
                                    *(int *)((int)param_3 + 0x18),0,0,nullptr);
                    *(undefined4 *)param_5 = 0;
                    return OK;
                }
                if (iVar5 == 0x10) {
                    DispatchCommand(this,iVar4,*(int *)((int)param_3 + 0x10),*(int *)((int)param_3 + 0x14),
                                    *(int *)((int)param_3 + 0x18),*(int *)((int)param_3 + 0x1c),0,nullptr);
                    *(undefined4 *)param_5 = 0;
                    return OK;
                }
                if ((iVar5 == 0x100) || (iVar5 == 0x400)) {
                    DispatchCommand(this,iVar4,0,0,0,0,*(int *)((int)param_3 + 0x10),
                                    (signed *)((int)param_3 + 0x14));
                    *(undefined4 *)param_5 = 0;
                    return OK;
                }
                if (iVar5 == 0x2000) {
                    DispatchCommand(this,iVar4,*(int *)((int)param_3 + 0x10),0,0,0,
                                    *(int *)((int)param_3 + 0x14),(signed *)((int)param_3 + 0x18));
                    *(undefined4 *)param_5 = 0;
                    return OK;
                }
                goto LAB_00072a40;
            }
            iVar5 = *(int *)((int)param_3 + 0x10);
            iVar6 = *(int *)((int)param_3 + 0x14);
        }
        DispatchCommand(this,iVar4,iVar5,iVar6,0,0,0,nullptr);
        *(undefined4 *)param_5 = 0;
        return OK;
    }
    if ((param_1 != 8) || (*(int *)((int)param_3 + 4) != 4)) goto switchD_00072a04_caseD_a;
    switch(*(undefined4 *)((int)param_3 + 0xc)) {
        case 0x8001:
            *(undefined4 *)((int)param_5 + 0x10) = 0x2050004;
            *(undefined4 *)param_5 = 0;
            *(undefined4 *)((int)param_5 + 8) = 4;
            *param_4 = 0x14;
            break;
        case 0x8002:
            goto LAB_00072a50;
        case 0x8003:
            bVar1 = *(byte *)&this->field_0x79;
            goto LAB_00072b54;
        case 0x8004:
            uVar7 = (uint)*(byte *)&this->field_0x5;
            *(undefined4 *)param_5 = 0;
            *(undefined4 *)((int)param_5 + 8) = 4;
            if (uVar7 != 0) {
                uVar7 = 1;
            }
            *(uint *)((int)param_5 + 0x10) = uVar7;
            *param_4 = 0x14;
            break;
        case 0x8005:
            bVar1 = *(byte *)&this->field_0x78;
        LAB_00072b54:
            uVar7 = (uint)bVar1;
            *(undefined4 *)param_5 = 0;
            *(undefined4 *)((int)param_5 + 8) = 4;
            if (uVar7 != 0) {
                LAB_00072b34:
                uVar7 = 1;
            }
            *(uint *)((int)param_5 + 0x10) = uVar7;
        LAB_00072b3c:
            *param_4 = 0x14;
            break;
        case 0x8006:
            local_28.tv_sec = 0;
            local_28.tv_usec = 0;
            gettimeofday(&local_28,nullptr);
            iVar4 = *(int *)&this->field_0x70;
            *(undefined4 *)param_5 = 0;
            *(undefined4 *)((int)param_5 + 8) = 4;
            iVar4 = (local_28.tv_sec * 1000 + local_28.tv_usec / 1000) - iVar4;
            if (iVar4 < 0) {
                iVar4 = -iVar4;
            }
            if (4999 < iVar4) {
                *(undefined4 *)((int)param_5 + 0x10) = 0;
                goto LAB_00072b3c;
            }
            goto LAB_00072b34;
        case 0x8007:
            uVar3 = this->field_0x7c;
            *(undefined4 *)param_5 = 0;
            *(undefined4 *)((int)param_5 + 0x10) = uVar3;
            *(undefined4 *)((int)param_5 + 8) = 4;
            *param_4 = 0x14;
            break;
        case 0x8008:
            uVar7 = this->samplerate;
            *(undefined4 *)((int)param_5 + 8) = 4;
            *(undefined4 *)param_5 = 0;
            *(uint *)((int)param_5 + 0x10) = uVar7;
            *param_4 = 0x14;
            break;
        case 0x8009:
        LAB_00072a50:
            *(undefined4 *)param_5 = 0;
            *(undefined4 *)((int)param_5 + 8) = 4;
            *(undefined4 *)((int)param_5 + 0x10) = 1;
            *param_4 = 0x14;
            break;
        case 0x800a:
            this_00 = this->convolver;
            *(undefined4 *)param_5 = 0;
            *(undefined4 *)((int)param_5 + 8) = 4;
            if (this_00 != nullptr) {
                this_00 = (Convolver *)Convolver::GetKernelID(this_00);
            }
            *(Convolver **)((int)param_5 + 0x10) = this_00;
            goto LAB_00072b3c;
        default:
            goto switchD_00072a04_caseD_a;
    }
    return OK;
}
