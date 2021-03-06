/*
 * analyzergain.h
 *
 *  Created on: 13/ott/2010
 *      Author: Vittorio Colao
 *       */

#ifndef ANALYZER_ANALYZERGAIN_H
#define ANALYZER_ANALYZERGAIN_H

#include "analyzer/analyzer.h"
#include "preferences/replaygainsettings.h"

class ReplayGain;

class AnalyzerGain : public Analyzer {
  public:
    AnalyzerGain(UserSettingsPointer pConfig);
    virtual ~AnalyzerGain();

    static bool isEnabled(const ReplayGainSettings& rgSettings) {
        return rgSettings.isAnalyzerEnabled(1);
    }

    bool initialize(TrackPointer tio, int sampleRate, int totalSamples) override;
    bool isDisabledOrLoadStoredSuccess(TrackPointer tio) const override;
    void process(const CSAMPLE* pIn, const int iLen) override;
    void cleanup(TrackPointer tio) override;
    void finalize(TrackPointer tio) override;

  private:
    bool m_initalized;
    ReplayGainSettings m_rgSettings;
    CSAMPLE* m_pLeftTempBuffer;
    CSAMPLE* m_pRightTempBuffer;
    ReplayGain* m_pReplayGain;
    int m_iBufferSize;
};

#endif /* ANALYZER_ANALYZERGAIN_H */
