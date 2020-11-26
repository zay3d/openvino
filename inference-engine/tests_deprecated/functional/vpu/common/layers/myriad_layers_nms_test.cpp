// Copyright (C) 2018-2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "myriad_layers_nms_test.hpp"

INSTANTIATE_TEST_CASE_P(accuracy, myriadLayersTestsNonMaxSuppression_smoke,
    ::testing::Values(
            MAKE_STRUCT(NMS_testParams,
                        {6, 1, 1}, // {spatial_dimension, num_classes, num_batches}
                        1,
                        {3},
                        {0.5f},
                        {0.f},
                        { // batches
                                { // spatial_dimension
                                        {0.5f, 0.5f, 1.0f, 1.0f}, // center_point_box=0 {y1, x1, y2, x2}  center_point_box=1 {y0, x0, w, h}
                                        {0.5f, 0.6f, 1.0f, 1.0f},
                                        {0.5f, 0.4f, 1.0f, 1.0f},
                                        {0.5f, 10.5f, 1.0f, 1.0f},
                                        {0.5f, 10.6f, 1.0f, 1.0f},
                                        {0.5f, 100.5f, 1.0f, 1.0f},
                                },
                        },
                        { // batches
                                { // classes
                                        {0.9f, 0.75f, 0.6f, 0.95f, 0.5f, 0.3f}, // spatial_dimension
                                },
                        },
                        { // num_selected_indices
                                {0, 0, 3}, // {batch_index, class_index, box_index}
                                {0, 0, 0},
                                {0, 0, 5},
                        }
            ),
            MAKE_STRUCT(NMS_testParams,
                        {6, 1, 1},
                        0,
                        {3},
                        {0.5f},
                        {0.f},
                        {
                                {
                                        {1.0f, 1.0f, 0.0f, 0.0f},
                                        {0.0f, 0.1f, 1.0f, 1.1f},
                                        {0.0f, 0.9f, 1.0f, -0.1f},
                                        {0.0f, 10.0f, 1.0f, 11.0f},
                                        {1.0f, 10.1f, 0.0f, 11.1f},
                                        {1.0f, 101.0f, 0.0f, 100.0f}
                                }
                        },
                        {
                                {
                                        {0.9f, 0.75f, 0.6f, 0.95f, 0.5f, 0.3f}
                                }
                        },
                        {
                                {0, 0, 3},
                                {0, 0, 0},
                                {0, 0, 5},
                        }
            ),
            MAKE_STRUCT(NMS_testParams,
                        {10, 1, 1},
                        0,
                        {3},
                        {0.5f},
                        {0.f},
                        {
                                {
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                }
                        },
                        {
                                {
                                        {0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f}
                                }
                        },
                        {
                                {0, 0, 0},
                        }
            ),
            MAKE_STRUCT(NMS_testParams,
                        {6, 1, 1},
                        0,
                        {2},
                        {0.5f},
                        {0.f},
                        {
                                {
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.1f, 1.0f, 1.1f},
                                        {0.0f, -0.1f, 1.0f, 0.9f},
                                        {0.0f, 10.0f, 1.0f, 11.0f},
                                        {0.0f, 10.1f, 1.0f, 11.1f},
                                        {0.0f, 100.0f, 1.0f, 101.0f},
                                }
                        },
                        {
                                {
                                        {0.9f, 0.75f, 0.6f, 0.95f, 0.5f, 0.3f}
                                }
                        },
                        {
                                {0, 0, 3},
                                {0, 0, 0},
                        }
            ),
            MAKE_STRUCT(NMS_testParams,
                        {1, 1, 1},
                        0,
                        {3},
                        {0.5f},
                        {0.f},
                        {
                                {
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                }
                        },
                        {
                                {
                                        {0.9f}
                                }
                        },
                        {
                                {0, 0, 0},
                        }
            ),
            MAKE_STRUCT(NMS_testParams,
                        {6, 1, 1},
                        0,
                        {3},
                        {0.5f},
                        {0.f},
                        {
                                {
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.1f, 1.0f, 1.1f},
                                        {0.0f, -0.1f, 1.0f, 0.9f},
                                        {0.0f, 10.0f, 1.0f, 11.0f},
                                        {0.0f, 10.1f, 1.0f, 11.1f},
                                        {0.0f, 100.0f, 1.0f, 101.0f},
                                }
                        },
                        {
                                {
                                        {0.9f, 0.75f, 0.6f, 0.95f, 0.5f, 0.3f}
                                }
                        },
                        {
                                {0, 0, 3},
                                {0, 0, 0},
                                {0, 0, 5},
                        }
            ),
            MAKE_STRUCT(NMS_testParams,
                        {6, 1, 1},
                        0,
                        {3},
                        {0.5f},
                        {0.4f},
                        {
                                {
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.1f, 1.0f, 1.1f},
                                        {0.0f, -0.1f, 1.0f, 0.9f},
                                        {0.0f, 10.0f, 1.0f, 11.0f},
                                        {0.0f, 10.1f, 1.0f, 11.1f},
                                        {0.0f, 100.0f, 1.0f, 101.0f},
                                }
                        },
                        {
                                {
                                        {0.9f, 0.75f, 0.6f, 0.95f, 0.5f, 0.3f}
                                }
                        },
                        {
                                {0, 0, 3},
                                {0, 0, 0},
                        }
            ),
            MAKE_STRUCT(NMS_testParams,
                        {6, 1, 2},
                        0,
                        {2},
                        {0.5f},
                        {0.0f},
                        {
                                {
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.1f, 1.0f, 1.1f},
                                        {0.0f, -0.1f, 1.0f, 0.9f},
                                        {0.0f, 10.0f, 1.0f, 11.0f},
                                        {0.0f, 10.1f, 1.0f, 11.1f},
                                        {0.0f, 100.0f, 1.0f, 101.0f},
                                },
                                {
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.1f, 1.0f, 1.1f},
                                        {0.0f, -0.1f, 1.0f, 0.9f},
                                        {0.0f, 10.0f, 1.0f, 11.0f},
                                        {0.0f, 10.1f, 1.0f, 11.1f},
                                        {0.0f, 100.0f, 1.0f, 101.0f},
                                }
                        },
                        {
                                {
                                        {0.9f, 0.75f, 0.6f, 0.95f, 0.5f, 0.3f}
                                },
                                {
                                        {0.9f, 0.75f, 0.6f, 0.95f, 0.5f, 0.3f}
                                }
                        },
                        {
                                {0, 0, 3},
                                {0, 0, 0},
                                {1, 0, 3},
                                {1, 0, 0},
                        }
            ),
            MAKE_STRUCT(NMS_testParams,
                        {6, 2, 1},
                        0,
                        {2},
                        {0.5f},
                        {0.0f},
                        {
                                {
                                        {0.0f, 0.0f, 1.0f, 1.0f},
                                        {0.0f, 0.1f, 1.0f, 1.1f},
                                        {0.0f, -0.1f, 1.0f, 0.9f},
                                        {0.0f, 10.0f, 1.0f, 11.0f},
                                        {0.0f, 10.1f, 1.0f, 11.1f},
                                        {0.0f, 100.0f, 1.0f, 101.0f},
                                }
                        },
                        {
                                {
                                        {0.9f, 0.75f, 0.6f, 0.95f, 0.5f, 0.3f},
                                        {0.9f, 0.75f, 0.6f, 0.95f, 0.5f, 0.3f}
                                }
                        },
                        {
                                {0, 0, 3},
                                {0, 0, 0},
                                {0, 1, 3},
                                {0, 1, 0},
                        }
            )
    )
);