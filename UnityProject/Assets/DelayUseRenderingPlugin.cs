using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DelayUseRenderingPlugin : MonoBehaviour
{
    // Start is called before the first frame update
    IEnumerator Start()
    {
        Debug.Log($"Waiting for a bit");
        yield return new WaitForSeconds(1f);
        Debug.Log($"About to load rendering plugin");
        
        var renderingPlugin = gameObject.AddComponent<UseRenderingPlugin>();
        Debug.Log($"added rendering plugin");
    }

}
